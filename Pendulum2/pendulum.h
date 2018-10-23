#pragma once

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;
#define PENDULUM

typedef unsigned int uint;
const double TINY = 1.0e-20;
inline void tilde(double *a, double *b) {
	*(b++) = 0;	*(b++) = -a[2];	*(b++) = a[1];
	*(b++) = a[2];	*(b++) = 0;	*(b++) = -a[0];
	*(b++) = -a[1];	*(b++) = a[0];	*(b++) = 0;
}

class Integrator {
public:
	Integrator(double h, uint array_size) {
		step_size = h;
		n = array_size;
		Y_next = new double[n];
		AW = new double[n * 2];
		AW1 = new double[n * 2];
	};
	~Integrator() {
		delete[] Y_next;
		delete[] AW;
		delete[] AW1;
	};

	void absh3(double *Y, double *Yp, double t_current) {
		/* ABSH3 : constant step Adams Bashforth 3rd order formulation.
	written by Sung-Soo Kim
	Date: Oct. 19, 1998
	copyright reserved by Sung-Soo Kim

	input variables
	t_current: current time
	Y : current state
	Yp : current derivative of state
	step_size: integration step_size

	output variables
	Y_next : state at next time step
	t_next : Next time

	STARTER: upto 2h, i.e., derivatives are stored for the initial  time steps at 0, h, 2h, to form
	3rd order Adams Bashforth formula */

		switch (intcount)
		{
		case 1:
			// Forward Euler method with 0.25 step_size for initial step
			// use derivative information at 0 step
			// y=y+step_size*Yp/4.0;
			for (uint i = 0; i < n; i++) {
				Y_next[i] = Y[i] + step_size * Yp[i] / 4.0;
			}
			// w(:,2) = Yp;
			for (uint i = 0; i < n; i++) {
				AW[i*2+1] = Yp[i];
			}
			// w1(:,2) = Yp;
			for (uint i = 0; i < n; i++) {
				AW1[i*2+1] = Yp[i];
			}
			t_next = t_current + step_size / 4.0;
			break;
		case 2:
			// Adams Bashforth 2nd order method with 0.25 step_size for 2nd step
			// use derivative information at 0, h/4
			// y = y + step_size_h * ( 3.0*Yp - w1(:,2))/8.0;
			for (uint i = 0; i < n; i++) {
				Y_next[i] = Y[i] + step_size * (3 * Yp[i] - AW1[i*2+1]) / 8.0;
			}
			// w1(:,1) = Yp;
			for (uint i = 0; i < n; i++) {
				AW1[i*2] = Yp[i];
			}
			t_next = t_current + step_size / 4.0;
			break;
		case 3:
			// Adams Bashforth 3rd order method with 0.25 step_size for 3rd step
			// use derivative information at 0, h/4, h/2
			// y = y + step_size * ( 23.0*Yp - 16.0*w1(:,1) + 5.0*w1(:,2))/48.0;
			for (uint i = 0; i < n; i++) {
				Y_next[i] = Y[i] + step_size * (23.0*Yp[i] - 16.0*AW1[i*2] + 5.0*AW1[i*2+1]) / 48.0;
			}
			// w1(:,2) = w1(:,1);
			for (uint i = 0; i < n; i++) {
				AW1[i*2+1] = AW1[i*2];
			}
			// w1(:,1) = Yp;
			for (uint i = 0; i < n; i++) {
				AW1[i*2] = Yp[i];
			}
			t_next = t_current + step_size / 4.0;
			break;
		case 4:
			// Adams Bashforth 3rd order method with 0.25 step_size for 4th step
			// use derivative information at h/4, h/2, 3h/4
			// y = y + step_size * ( 23.0*Yp - 16.0*w1(:,1) + 5.0*w1(:,2))/48.0;
			for (uint i = 0; i < n; i++) {
				Y_next[i] = Y[i] + step_size * (23.0*Yp[i] - 16.0*AW1[i*2] + 5.0*AW1[i*2+1]) / 48.0;
			}
			// w1(:,2) = w(:,2);
			for (uint i = 0; i < n; i++) {
				AW1[i*2+1] = AW[i*2+1];
			}
			t_next = t_current + step_size / 4.0;
			break;
		case 5:
			// Adams Bashforth 3rd order method with 0.5 step_size for 5th step
			// use derivative information at 0, h/2, h
			// y = y + step_size * ( 23.0*Yp - 16.0*w1(:,1) + 5.0*w1(:,2))/24.0;
			for (uint i = 0; i < n; i++) {
				Y_next[i] = Y[i] + step_size * (23.0*Yp[i] - 16.0*AW1[i*2] + 5.0*AW1[i*2+1]) / 24.0;
			}
			// w(:,1) = Yp;
			for (uint i = 0; i < n; i++) {
				AW[i*2] = Yp[i];
			}
			// w1(:,2) = w1(:,1);
			for (uint i = 0; i < n; i++) {
				AW1[i*2+1] = AW1[i*2];
			}
			// w1(:,1) = Yp;
			for (uint i = 0; i < n; i++) {
				AW1[i*2] = Yp[i];
			}
			t_next = t_current + step_size / 2.0;
			break;
		case 6:
			// Adams Bashforth 3rd order method with 0.5 step_size for 6th step
			// use derivative information at h/2, h,  3h/2
			// y = y + step_size * ( 23.0*Yp - 16.0*w1(:,1) + 5.0*w1(:,2))/24.0;
			for (uint i = 0; i < n; i++) {
				Y_next[i] = Y[i] + step_size * (23.0*Yp[i] - 16.0*AW1[i*2] + 5.0*AW1[i*2+1]) / 24.0;
			}
			// w1(:,2) = w1(:,1);
			for (uint i = 0; i < n; i++) {
				AW1[i*2+1] = AW1[i*2];
			}
			// w1(:,1) = Yp;
			for (uint i = 0; i < n; i++) {
				AW1[i*2] = Yp[i];
			}
			t_next = t_current + step_size / 2.0;
			break;
		case 7:
			// Adams Bashforth 3rd order method with step_size for 7th step
			// use derivative information at 0,  h,  2h
			// y = y + step_size * ( 23.0*Yp - 16.0*w(:,1) + 5.0*w(:,2))/12.0;
			for (uint i = 0; i < n; i++) {
				Y_next[i] = Y[i] + step_size * (23.0*Yp[i] - 16.0*AW[i*2] + 5.0*AW[i*2+1]) / 12.0;
			}
			// w(:,2) = w(:,1);
			for (uint i = 0; i < n; i++) {
				AW[i*2+1] = AW[i*2];
			}
			// w(:,1) = Yp;
			for (uint i = 0; i < n; i++) {
				AW[i*2] = Yp[i];
			}
			t_next = t_current + step_size;
			break;
		default:
			// Adams Bashforth 3rd order method with step_size for more than 8th step
			// use derivative information t_current-2h, t_current-h, t_current
			// y = y + step_size * ( 23.0*Yp - 16.0*w(:,1) + 5.0*w(:,2))/12.0;
			for (uint i = 0; i < n; i++) {
				Y_next[i] = Y[i] + step_size * (23.0*Yp[i] - 16.0*AW[i*2] + 5.0*AW[i*2+1]) / 12.0;
			}
			// w(:,2) = w(:,1);
			for (uint i = 0; i < n; i++) {
				AW[i*2+1] = AW[i*2];
			}
			// w(:,1) = Yp;
			for (uint i = 0; i < n; i++) {
				AW[i*2] = Yp[i];
			}
			t_next = t_current + step_size;
			break;
		}
		intcount++;
	}

	double *Y_next;
	double t_next = 0, step_size;
	uint intcount = 1, n = 0;
private:
	double *AW, *AW1;
};

class Body
{
public:
	Body() {
		u_vec[0] = 0;
		u_vec[1] = 0;
		u_vec[2] = 1;
	};
	~Body() {};
	// base body information
	double A0[9], C01[9], s01p[3];
	// body initial data
	double qi = 0, qi_dot = 0, mi = 0;
	double ri[3], ri_dot[3], wi[3], rhoip[3], sijp[3], Jip[9], Cii[9], Cij[9];
	// Orientation
	double Aijpp[9], Ai[9], Hi[3], u_vec[3];
	// Position
	double sij[3], rhoi[3], ric[3], rit[9];
	// Velocity State
	double Bi[6], Yih[6];
	// Cartesian velocity state
	double Ti[36], wit[9], Yib[6], ric_dot[3];
	// Mass & Force
	double Jic[9], rict[9], rict_dot[9], Mih[36], Fic[3], Tic[3], Qih[6];
	// Velocity Coupling
	double rit_dot[9], dHi[3], Di[6];
	// System EQM
	double Ki[36], Li[6];
	// Acceleration
	double qi_ddot;
	// Generalized Force(Torque)
	double Q = 0;
	// Gravity force
	double Fg[6], F[6];
	double Tg = 0, T;
	// Control
	double des_vel = 0, err_vel = 0, err_vel_accum = 0, err_vel_prev = 0, T_control = 0, T_control_vel = 0, Kp_vel = 0, Ki_vel = 0, Kd_vel = 0;
	// Residual
	double r_hat = 0, K = 0, p = 0, Ta = 0, Td = 0, yp = 0;
};

class Pendulum
{
public:
	Pendulum(uint numbody);
	~Pendulum();
	void run();

private:
	uint num_body;
	Body *body;
	Integrator *integr;
	// system variable
	double start_time, end_time, h, g, t_current;
	// state vector
	double *Y, *Yp;
	// file
	char file_name[256];
	FILE *fp;

 	void analysis();
 		void Y2qdq();
 		void kinematics_analysis();
 		void dynamics_analysis();
 			void GeneralizedMassForce();
 			void ludcmp(double *a, int n, uint* indx, double d, double *fac);
 			void lubksb(double *fac, int n, uint* indx, double *b, double *x);
 		void dqddq2Yp();
 	void save_data();
};