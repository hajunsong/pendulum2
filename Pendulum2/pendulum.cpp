#include "pendulum.h"
#include "dob.h"

Pendulum::Pendulum(uint numbody) {
	num_body = numbody;
	body = new Body[num_body];

	// read data
	start_time = 0;
	end_time = 5;
	h = 0.001;
	g = -9.80665;

	double *A0_ptr = body[0].A0;
	double *C01_ptr = body[0].C01;
	*(A0_ptr++) = 0;	*(A0_ptr++) = 0;	*(A0_ptr++) = 1;
	*(A0_ptr++) = 1;	*(A0_ptr++) = 0;	*(A0_ptr++) = 0;
	*(A0_ptr++) = 0;	*(A0_ptr++) = 1;	*(A0_ptr) = 0;
	*(C01_ptr++) = 1;	*(C01_ptr++) = 0;	*(C01_ptr++) = 0;
	*(C01_ptr++) = 0;	*(C01_ptr++) = 1;	*(C01_ptr++) = 0;
	*(C01_ptr++) = 0;	*(C01_ptr++) = 0;	*(C01_ptr) = 1;
	memset(body[0].s01p, 0, sizeof(double)*3);
	
	double *Jip_ptr, *rhoip_ptr, *Cii_ptr, *Cij_ptr, *sijp_ptr;
	switch (num_body) {
	case 6:
		// body 6 variable
		body[5].qi = 0;
		body[5].qi_dot = 0;
		body[5].mi = 25;
		Jip_ptr = body[5].Jip;
		*(Jip_ptr++) = 12;	*(Jip_ptr++) = 0;	*(Jip_ptr++) = 0;
		*(Jip_ptr++) = 0;	*(Jip_ptr++) = 12;	*(Jip_ptr++) = 0;
		*(Jip_ptr++) = 0;	*(Jip_ptr++) = 0;	*(Jip_ptr) = 12;
		rhoip_ptr = body[5].rhoip;
		*(rhoip_ptr++) = 0;	*(rhoip_ptr++) = -0.4;	*(rhoip_ptr++) = 0;
		Cii_ptr = body[5].Cii;
		*(Cii_ptr++) = 0;	*(Cii_ptr++) = 1;	*(Cii_ptr++) = 0;
		*(Cii_ptr++) = 0;	*(Cii_ptr++) = 0;	*(Cii_ptr++) = 1;
		*(Cii_ptr++) = 1;	*(Cii_ptr++) = 0;	*(Cii_ptr) = 0;
		Cij_ptr = body[5].Cij;
		*(Cij_ptr++) = 0;	*(Cij_ptr++) = -1;	*(Cij_ptr++) = 0;
		*(Cij_ptr++) = 1;	*(Cij_ptr++) = 0;	*(Cij_ptr++) = 0;
		*(Cij_ptr++) = 0;	*(Cij_ptr++) = 0;	*(Cij_ptr) = 1;
		sijp_ptr = body[5].sijp;
		*(sijp_ptr++) = 0;	*(sijp_ptr++) = -0.8;	*(sijp_ptr++) = 0;
		body[5].K = 1500;
		goto CASE5;
	CASE5: case 5:
		// body 5 variable
		body[4].qi = 0;
		body[4].qi_dot = 0;
		body[4].mi = 20;
		Jip_ptr = body[4].Jip;
		*(Jip_ptr++) = 10;	*(Jip_ptr++) = 0;	*(Jip_ptr++) = 0;
		*(Jip_ptr++) = 0;	*(Jip_ptr++) = 10;	*(Jip_ptr++) = 0;
		*(Jip_ptr++) = 0;	*(Jip_ptr++) = 0;	*(Jip_ptr) = 10;
		rhoip_ptr = body[4].rhoip;
		*(rhoip_ptr++) = 0.35;	*(rhoip_ptr++) = 0;	*(rhoip_ptr++) = 0;
		Cii_ptr = body[4].Cii;
		*(Cii_ptr++) = 0;	*(Cii_ptr++) = 0;	*(Cii_ptr++) = -1;
		*(Cii_ptr++) = 0;	*(Cii_ptr++) = 1;	*(Cii_ptr++) = 0;
		*(Cii_ptr++) = 1;	*(Cii_ptr++) = 0;	*(Cii_ptr) = 0;
		Cij_ptr = body[4].Cij;
		*(Cij_ptr++) = 0;	*(Cij_ptr++) = -1;	*(Cij_ptr++) = 0;
		*(Cij_ptr++) = 1;	*(Cij_ptr++) = 0;	*(Cij_ptr++) = 0;
		*(Cij_ptr++) = 0;	*(Cij_ptr++) = 0;	*(Cij_ptr) = 1;
		sijp_ptr = body[4].sijp;
		*(sijp_ptr++) = 0.7;	*(sijp_ptr++) = 0;	*(sijp_ptr++) = 0;
		body[4].K = 1500;
		goto CASE4;
	CASE4: case 4:
		// body 4 variable
		body[3].qi = 0;
		body[3].qi_dot = 0;
		body[3].mi = 15;
		Jip_ptr = body[3].Jip;
		*(Jip_ptr++) = 7;	*(Jip_ptr++) = 0;	*(Jip_ptr++) = 0;
		*(Jip_ptr++) = 0;	*(Jip_ptr++) = 7;	*(Jip_ptr++) = 0;
		*(Jip_ptr++) = 0;	*(Jip_ptr++) = 0;	*(Jip_ptr) = 7;
		rhoip_ptr = body[3].rhoip;
		*(rhoip_ptr++) = 0;	*(rhoip_ptr++) = 0.3;	*(rhoip_ptr++) = 0;
		Cii_ptr = body[3].Cii;
		*(Cii_ptr++) = 0;	*(Cii_ptr++) = -1;	*(Cii_ptr++) = 0;
		*(Cii_ptr++) = 0;	*(Cii_ptr++) = 0;	*(Cii_ptr++) = -1;
		*(Cii_ptr++) = 1;	*(Cii_ptr++) = 0;	*(Cii_ptr) = 0;
		Cij_ptr = body[3].Cij;
		*(Cij_ptr++) = 0;	*(Cij_ptr++) = -1;	*(Cij_ptr++) = 0;
		*(Cij_ptr++) = 1;	*(Cij_ptr++) = 0;	*(Cij_ptr++) = 0;
		*(Cij_ptr++) = 0;	*(Cij_ptr++) = 0;	*(Cij_ptr) = 1;
		sijp_ptr = body[3].sijp;
		*(sijp_ptr++) = 0;	*(sijp_ptr++) = 0.6;	*(sijp_ptr++) = 0;
		body[3].K = 1500;
		goto CASE3;
	CASE3: case 3:
		// body 3 variable
		body[2].qi = 0;
		body[2].qi_dot = 0;
		body[2].mi = 10;
		Jip_ptr = body[2].Jip;
		*(Jip_ptr++) = 5;	*(Jip_ptr++) = 0;	*(Jip_ptr++) = 0;
		*(Jip_ptr++) = 0;	*(Jip_ptr++) = 5;	*(Jip_ptr++) = 0;
		*(Jip_ptr++) = 0;	*(Jip_ptr++) = 0;	*(Jip_ptr) = 5;
		rhoip_ptr = body[2].rhoip;
		*(rhoip_ptr++) = -0.25;	*(rhoip_ptr++) = 0;	*(rhoip_ptr++) = 0;
		Cii_ptr = body[2].Cii;
		*(Cii_ptr++) = 0;	*(Cii_ptr++) = 0;	*(Cii_ptr++) = 1;
		*(Cii_ptr++) = 0;	*(Cii_ptr++) = -1;	*(Cii_ptr++) = 0;
		*(Cii_ptr++) = 1;	*(Cii_ptr++) = 0;	*(Cii_ptr) = 0;
		Cij_ptr = body[2].Cij;
		*(Cij_ptr++) = 0;	*(Cij_ptr++) = -1;	*(Cij_ptr++) = 0;
		*(Cij_ptr++) = 1;	*(Cij_ptr++) = 0;	*(Cij_ptr++) = 0;
		*(Cij_ptr++) = 0;	*(Cij_ptr++) = 0;	*(Cij_ptr) = 1;
		sijp_ptr = body[2].sijp;
		*(sijp_ptr++) = -0.5;	*(sijp_ptr++) = 0;	*(sijp_ptr++) = 0;
		body[2].K = 1500;
		goto CASE2;
	CASE2: case 2:
		// body 2 variable
		body[1].qi = 0;
		body[1].qi_dot = 0;
		body[1].mi = 5;
		Jip_ptr = body[1].Jip;
		*(Jip_ptr++) = 3;	*(Jip_ptr++) = 0;	*(Jip_ptr++) = 0;
		*(Jip_ptr++) = 0;	*(Jip_ptr++) = 3;	*(Jip_ptr++) = 0;
		*(Jip_ptr++) = 0;	*(Jip_ptr++) = 0;	*(Jip_ptr) = 3;
		rhoip_ptr = body[1].rhoip;
		*(rhoip_ptr++) = 0;	*(rhoip_ptr++) = -0.2;	*(rhoip_ptr++) = 0;
		Cii_ptr = body[1].Cii;
		*(Cii_ptr++) = 0;	*(Cii_ptr++) = 1;	*(Cii_ptr++) = 0;
		*(Cii_ptr++) = 0;	*(Cii_ptr++) = 0;	*(Cii_ptr++) = 1;
		*(Cii_ptr++) = 1;	*(Cii_ptr++) = 0;	*(Cii_ptr) = 0;
		Cij_ptr = body[1].Cij;
		*(Cij_ptr++) = 0;	*(Cij_ptr++) = -1;	*(Cij_ptr++) = 0;
		*(Cij_ptr++) = 1;	*(Cij_ptr++) = 0;	*(Cij_ptr++) = 0;
		*(Cij_ptr++) = 0;	*(Cij_ptr++) = 0;	*(Cij_ptr) = 1;
		sijp_ptr = body[1].sijp;
		*(sijp_ptr++) = 0;	*(sijp_ptr++) = -0.4;	*(sijp_ptr++) = 0;
		body[1].K = 1500;
		goto CASE1;
	CASE1: case 1:
		// body 1 variable
		body[0].qi = 0;
		body[0].qi_dot = 0;
		body[0].mi = 2;
		Jip_ptr = body[0].Jip;
		*(Jip_ptr++) = 1.5;	*(Jip_ptr++) = 0;	*(Jip_ptr++) = 0;
		*(Jip_ptr++) = 0;	*(Jip_ptr++) = 1.5;	*(Jip_ptr++) = 0;
		*(Jip_ptr++) = 0;	*(Jip_ptr++) = 0;	*(Jip_ptr) = 1.5;
		rhoip_ptr = body[0].rhoip;
		*(rhoip_ptr++) = 0.15;	*(rhoip_ptr++) = 0;	*(rhoip_ptr++) = 0;
		Cii_ptr = body[0].Cii;
		*(Cii_ptr++) = 0;	*(Cii_ptr++) = 0;	*(Cii_ptr++) = -1;
		*(Cii_ptr++) = 0;	*(Cii_ptr++) = 1;	*(Cii_ptr++) = 0;
		*(Cii_ptr++) = 1;	*(Cii_ptr++) = 0;	*(Cii_ptr) = 0;
		Cij_ptr = body[0].Cij;
		*(Cij_ptr++) = 0;	*(Cij_ptr++) = -1;	*(Cij_ptr++) = 0;
		*(Cij_ptr++) = 1;	*(Cij_ptr++) = 0;	*(Cij_ptr++) = 0;
		*(Cij_ptr++) = 0;	*(Cij_ptr++) = 0;	*(Cij_ptr) = 1;
		sijp_ptr = body[0].sijp;
		*(sijp_ptr++) = 0.3;	*(sijp_ptr++) = 0;	*(sijp_ptr++) = 0;
		body[0].K = 1500;
	}
	
	// define Y vector
	Y = new double[2 * num_body];
	Yp = new double[2 * num_body];

	if (num_body == 1) {
		Y[0] = body[0].qi;
		Y[1] = body[0].qi_dot;
	}
	else {
		double *Y_ptr = Y;
		for (uint i = 0; i < num_body; i++) {
			*(Y_ptr++) = body[i].qi;
		}
		for (uint i = 0; i < num_body; i++) {
			*(Y_ptr++) = body[i].qi_dot;
		}
	}

	integr = new Integrator(h, 2*num_body);
}

Pendulum::~Pendulum()
{
	delete[] body;
	delete integr;
	delete[] Y;
	delete[] Yp;
}

void Pendulum::run() {
	sprintf_s(file_name, 256, "C_body%d.txt", num_body);
	fopen_s(&fp, file_name, "w+");

	DOB *dob = new DOB(num_body);

	while (t_current <= end_time) {
		analysis();
		double *q = new double[num_body], *q_dot = new double[num_body], *tau = new double[num_body];
		for (uint i = 0; i < num_body; i++) {
			q[i] = body[i].qi;
			q_dot[i] = body[i].qi_dot;
			tau[i] = -body[i].Tg;
		}
		dob->run(q, q_dot, tau);
		save_data();
		integr->absh3(Y, Yp, t_current);
		printf("Time : %.3f[s]\n", t_current);
		memcpy(Y, integr->Y_next, sizeof(double)*num_body*2);
		t_current = integr->t_next;

		delete[] q;
		delete[] q_dot;
		delete[] tau;
	}

	delete dob;

	fclose(fp);
}

void Pendulum::analysis() {
	Y2qdq();

	kinematics_analysis();
	GeneralizedMassForce();
	dynamics_analysis();

	dqddq2Yp();
}

void Pendulum::Y2qdq()
{
	double *Y_ptr = Y;
	for (uint i = 0; i < num_body; i++) {
		body[i].qi = *(Y_ptr++);
	}
	for (uint i = 0; i < num_body; i++) {
		body[i].qi_dot = *(Y_ptr++);
	}
}

void Pendulum::kinematics_analysis() {
	for (uint indx = 0; indx < num_body; indx++) {
		// Orientation
		double *Aijpp_ptr = body[indx].Aijpp;
		*(Aijpp_ptr++) = cos(body[indx].qi);	*(Aijpp_ptr++) = -sin(body[indx].qi);	*(Aijpp_ptr++) = 0;
		*(Aijpp_ptr++) = sin(body[indx].qi);	*(Aijpp_ptr++) = cos(body[indx].qi);	*(Aijpp_ptr++) = 0;
		*(Aijpp_ptr++) = 0;						*(Aijpp_ptr++) = 0;						*(Aijpp_ptr++) = 1;
		memset(body[indx].Hi, 0, sizeof(double)*3);
		memset(body[indx].Ai, 0, sizeof(double)*9);
		if (indx == 0) {
			double A0_C01[9] = { 0, };
			for (uint i = 0; i < 3; i++) {
				for (uint j = 0; j < 3; j++) {
					for (uint k = 0; k < 3; k++) {
						A0_C01[i * 3 + j] += body[indx].A0[i * 3 + k] * body[indx].C01[k * 3 + j];
					}
				}
			}
			for (uint i = 0; i < 3; i++) {
				for (uint j = 0; j < 3; j++) {
					body[indx].Hi[i] += A0_C01[i * 3 + j] * body[indx].u_vec[j];
					for (uint k = 0; k < 3; k++) {
						body[indx].Ai[i * 3 + j] += A0_C01[i * 3 + k] * body[indx].Aijpp[k * 3 + j];
					}
				}
			}
		}
		else {
			double Ai_Cij[9] = { 0, };
			for (uint i = 0; i < 3; i++) {
				for (uint j = 0; j < 3; j++) {
					for (uint k = 0; k < 3; k++) {
						Ai_Cij[i * 3 + j] += body[indx - 1].Ai[i * 3 + k] * body[indx - 1].Cij[k * 3 + j];
					}
				}
			}
			for (uint i = 0; i < 3; i++) {
				for (uint j = 0; j < 3; j++) {
					body[indx].Hi[i] += Ai_Cij[i * 3 + j] * body[indx].u_vec[j];
					for (uint k = 0; k < 3; k++) {
						body[indx].Ai[i * 3 + j] += Ai_Cij[i * 3 + k] * body[indx].Aijpp[k * 3 + j];
					}
				}
			}
		}
		// Position
		if (indx == 0) {
			memset(body[indx].ri, 0, sizeof(double)*3);
			for (uint i = 0; i < 3; i++) {
				for (uint j = 0; j < 3; j++) {
					body[indx].ri[i] += body[indx].A0[i * 3 + j] * body[indx].s01p[j];
				}
			}
		}
		else {
			memset(body[indx - 1].sij, 0, sizeof(double)*3);
			for (uint i = 0; i < 3; i++) {
				for (uint j = 0; j < 3; j++) {
					body[indx - 1].sij[i] += body[indx - 1].Ai[i * 3 + j] * body[indx - 1].sijp[j];
				}
				body[indx].ri[i] = body[indx - 1].ri[i] + body[indx - 1].sij[i];
			}
		}
		memset(body[indx].rhoi, 0, sizeof(double)*3);
		for (uint i = 0; i < 3; i++) {
			for (uint j = 0; j < 3; j++) {
				body[indx].rhoi[i] += body[indx].Ai[i * 3 + j] * body[indx].rhoip[j];
			}
			body[indx].ric[i] = body[indx].ri[i] + body[indx].rhoi[i];
		}
		// Inertial matrix
		double Ai_Cii[9] = { 0, };
		for (uint i = 0; i < 3; i++) {
			for (uint j = 0; j < 3; j++){
				for (uint k = 0; k < 3; k++) {
					Ai_Cii[i * 3 + j] += body[indx].Ai[i * 3 + k] * body[indx].Cii[k * 3 + j];
				}
			}
		}
		memset(body[indx].Jic, 0, sizeof(double) * 9);
		double temp[9] = { 0, };
		for (uint i = 0; i < 3; i++) {
			for (uint j = 0; j < 3; j++) {
				for (uint k = 0; k < 3; k++) {
					temp[i * 3 + j] += Ai_Cii[i * 3 + k] * body[indx].Jip[k * 3 + j];
				}
			}
		}
		for (uint i = 0; i < 3; i++) {
			for (uint j = 0; j < 3; j++) {
				body[indx].Jic[i * 3 + j] = 0;
				for (uint k = 0; k < 3; k++) {
					body[indx].Jic[i * 3 + j] += temp[i * 3 + k] * Ai_Cii[j*3 + k];
				}
			}
		}
	}
}

void Pendulum::GeneralizedMassForce() {
	for (uint indx = 0; indx < num_body; indx++) {
		// Velocity State
		tilde(body[indx].ri, body[indx].rit);
		memset(body[indx].Bi, 0, sizeof(double)*3);
		for (uint i = 0; i < 3; i++) {
			for (uint j = 0; j < 3; j++) {
				body[indx].Bi[i] += body[indx].rit[i * 3 + j] * body[indx].Hi[j];
			}
		}
		memcpy(body[indx].Bi + 3, body[indx].Hi, sizeof(double)*3);
		if (indx == 0) {
			for (uint i = 0; i < 6; i++) {
				body[indx].Yih[i] = body[indx].Bi[i] * body[indx].qi_dot;
			}
		}
		else {
			for (uint i = 0; i < 6; i++) {
				body[indx].Yih[i] = body[indx - 1].Yih[i] + body[indx].Bi[i] * body[indx].qi_dot;
			}
		}
		// Cartesian Velocity
		for (uint i = 0; i < 6; i++) {
			for (uint j = 0; j < 6; j++) {
				if (i < 3 && j >= 3) {
					body[indx].Ti[i * 6 + j] = -body[indx].rit[i * 3 + (j - 3)];
				}
				else {
					body[indx].Ti[i * 6 + j] = i == j ? 1 : 0;
				}
			}
		}
		memset(body[indx].Yib, 0, sizeof(double)*6);
		for (uint i = 0; i < 6; i++) {
			for (uint j = 0; j < 6; j++) {
				body[indx].Yib[i] += body[indx].Ti[i * 6 + j] * body[indx].Yih[j];
			}
		}
		memcpy(body[indx].ri_dot, body[indx].Yib, sizeof(double)*3);
		memcpy(body[indx].wi, body[indx].Yib + 3, sizeof(double)*3);
		tilde(body[indx].wi, body[indx].wit);
		memset(body[indx].ric_dot, 0, sizeof(double)*3);
		for (uint i = 0; i < 3; i++) {
			for (uint j = 0; j < 3; j++) {
				body[indx].ric_dot[i] += body[indx].wit[i * 3 + j] * body[indx].rhoi[j];
			}
			body[indx].ric_dot[i] += body[indx].ri_dot[i];
		}
		// Mass & Force
		tilde(body[indx].ric, body[indx].rict);
		tilde(body[indx].ric_dot, body[indx].rict_dot);
		double mi_rict[9] = { 0, };
		for (uint i = 0; i < 9; i++) {
				mi_rict[i] = body[indx].mi*body[indx].rict[i];
		}
		memset(body[indx].Mih, 0, sizeof(double)*36);
		for (uint i = 0; i < 3; i++) {
			for (uint j = 0; j < 3; j++) {
				body[indx].Mih[i * 6 + j] = i == j ? body[indx].mi : 0;
				body[indx].Mih[i * 6 + (j + 3)] = -mi_rict[i * 3 + j];
				body[indx].Mih[(i + 3) * 6 + j] = mi_rict[i * 3 + j];
				for (uint k = 0; k < 3; k++) {
					body[indx].Mih[(i + 3) * 6 + (j + 3)] += -mi_rict[i * 3 + k] * body[indx].rict[k * 3 + j];
				}
				body[indx].Mih[(i + 3) * 6 + (j + 3)] += body[indx].Jic[i * 3 + j];
			}
		}
		memset(body[indx].Fic, 0, sizeof(double)*3);
		memset(body[indx].Tic, 0, sizeof(double)*3);
		body[indx].Fic[2] = body[indx].mi*g;
		double mi_rict_drict_wi[3] = { 0, }, wit_Jic_wi[3] = { 0, };
		for (uint i = 0; i < 3; i++) {
			for (uint j = 0; j < 3; j++) {
				double temp1[3] = { 0, }, temp2[3] = { 0, };
				for (uint k = 0; k < 3; k++) {
					for (uint m = 0; m < 3; m++) {
						temp1[k] += body[indx].rict_dot[k * 3 + m] * body[indx].wi[m];
						temp2[k] += body[indx].Jic[k * 3 + m] * body[indx].wi[m];
					}
				}
				mi_rict_drict_wi[i] += mi_rict[i * 3 + j] * temp1[j];
				wit_Jic_wi[i] += body[indx].wit[i * 3 + j] * temp2[j];
			}
		}
		memset(body[indx].Qih, 0, sizeof(double) * 6);
		memset(body[indx].Qih_g, 0, sizeof(double) * 6);
		memset(body[indx].Qih_c, 0, sizeof(double) * 6);
		for (uint i = 0; i < 3; i++) {
			for (uint j = 0; j < 3; j++) {
				body[indx].Qih[i] += body[indx].rict_dot[i * 3 + j] * body[indx].wi[j];
				body[indx].Qih[i + 3] += body[indx].rict[i * 3 + j] * body[indx].Fic[j];
			}
			body[indx].Qih[i] *= body[indx].mi;
			body[indx].Qih[i] += body[indx].Fic[i];
			body[indx].Qih[i + 3] += (body[indx].Tic[i] + mi_rict_drict_wi[i] - wit_Jic_wi[i]);
		}
		for (uint i = 0; i < 3; i++) {
			for (uint j = 0; j < 3; j++) {
				body[indx].Qih_g[i + 3] += body[indx].rict[i * 3 + j] * body[indx].Fic[j];
				body[indx].Qih_c[i] += body[indx].rict_dot[i * 3 + j] * body[indx].wi[j];
			}
			body[indx].Qih_c[i] *= body[indx].mi;
			body[indx].Qih_g[i] = body[indx].Fic[i];
			body[indx].Qih_c[i + 3] += (mi_rict_drict_wi[i] - wit_Jic_wi[i]);
		}
		// Velocity Coupling
		tilde(body[indx].ri_dot, body[indx].rit_dot);
		memset(body[indx].dHi, 0, sizeof(double)*3);
		if (indx != 0) {
			for (uint i = 0; i < 3; i++) {
				for (uint j = 0; j < 3; j++) {
					body[indx].dHi[i] += body[indx - 1].wit[i*3 + j]*body[indx].Hi[j];
				}
			}
		}
		memset(body[indx].Di, 0, sizeof(double)*3);
		for (uint i = 0; i < 3; i++) {
			double temp1 = 0, temp2 = 0;
			for (uint j = 0; j < 3; j++) {
				temp1 += body[indx].rit_dot[i * 3 + j] * body[indx].Hi[j];
				temp2 += body[indx].rit[i * 3 + j] * body[indx].dHi[j];
			}
			body[indx].Di[i] = (temp1 + temp2)*body[indx].qi_dot;
			body[indx].Di[i + 3] = body[indx].dHi[i] * body[indx].qi_dot;
		}
	}

	for (int indx = num_body - 1; indx >= 0; indx--) {
		memcpy(body[indx].Ki, body[indx].Mih, sizeof(double)*36);
		memcpy(body[indx].Li, body[indx].Qih, sizeof(double)*6);
		memcpy(body[indx].Li_g, body[indx].Qih_g, sizeof(double)*6);
		memcpy(body[indx].Li_c, body[indx].Qih_c, sizeof(double)*6);
		if (indx != num_body - 1) {
			for (uint i = 0; i < 36; i++) {
				body[indx].Ki[i] += body[indx + 1].Ki[i];
			}
			for (uint i = 0; i < 6; i++) {
				double temp = 0;
				for (uint j = 0; j < 6; j++) {
					temp += body[indx + 1].Ki[i * 6 + j] * body[indx + 1].Di[j];
				}
				body[indx].Li[i] += (body[indx + 1].Li[i] - temp);
				body[indx].Li_g[i] += (body[indx + 1].Li_g[i] - temp);
				body[indx].Li_c[i] += (body[indx + 1].Li_c[i] - temp);
			}
		}
	}
}

void Pendulum::dynamics_analysis() {

	double *M = new double[num_body*num_body];
	double *Q = new double[num_body];
	memset(M, 0, sizeof(double)*num_body*num_body);
	memset(Q, 0, sizeof(double)*num_body);

	for (uint i = 0; i < num_body; i++) {
		for (uint j = 0; j < num_body; j++) {
			if (i == j) {
				double temp[6] = { 0, };
				for (uint m = 0; m < 6; m++) {
					for (uint n = 0; n < 6; n++) {
						temp[m] += body[i].Ki[m * 6 + n] * body[i].Bi[n];
					}
				}
				for (uint k = 0; k < 6; k++) {
					M[i*num_body + j] += body[i].Bi[k] * temp[k];
				}
			}
			else if (i < j) {
				double temp[6] = { 0, };
				for (uint m = 0; m < 6; m++) {
					for (uint n = 0; n < 6; n++) {
						temp[m] += body[j].Ki[m * 6 + n] * body[j].Bi[n];
					}
				}
				for (uint k = 0; k < 6; k++) {
					M[i*num_body + j] += body[i].Bi[k] * temp[k];
				}
			}
			else if (i > j) {
				double temp[6] = { 0, };
				for (uint m = 0; m < 6; m++) {
					for (uint n = 0; n < 6; n++) {
						temp[m] += body[i].Ki[m * 6 + n] * body[j].Bi[n];
					}
				}
				for (uint k = 0; k < 6; k++) {
					M[i*num_body + j] += body[i].Bi[k] * temp[k];
				}
			}
		}
		double D_temp[6] = { 0, };
		for (uint j = 0; j <= i; j++) {
			for (uint k = 0; k < 6; k++) {
				D_temp[k] += body[j].Di[k];
			}
		}
		
		double temp1[6] = { 0, };
		body[i].Tg = 0;
		body[i].Tc = 0;
		for (uint j = 0; j < 6; j++) {
			for (uint k = 0; k < 6; k++) {
				temp1[j] += body[i].Ki[j * 6 + k] * D_temp[k];
			}
			Q[i] += body[i].Bi[j] * (body[i].Li[j] - temp1[j]);
			body[i].Tg += body[i].Bi[j] * (body[i].Li_g[j] - temp1[j]);
			body[i].Tc += body[i].Bi[j] * (body[i].Li_c[j] - temp1[j]);
		}
		Q[i] += -body[i].Tg;
	}

	double *dYh = new double[num_body];
	double *fac = new double[num_body*num_body];
	uint *indx = new uint[num_body];
	int n = num_body;
	ludcmp(M, n, indx, 0.0, fac);
	lubksb(fac, n, indx, Q, dYh);

	double *dYh_ptr = dYh;
	for (uint i = 0; i < num_body; i++) {
		body[i].qi_ddot = *(dYh_ptr++);
	}

	delete[] M;
	delete[] Q;
	delete[] dYh;
	delete[] fac;
	delete[] indx;
}

void Pendulum::dqddq2Yp() {
	double *Yp_ptr = Yp;
	for (uint i = 0; i < num_body; i++) {
		*(Yp_ptr++) = body[i].qi_dot;
	}
	for (uint i = 0; i < num_body; i++) {
		*(Yp_ptr++) = body[i].qi_ddot;
	}
}

void Pendulum::save_data()
{
	fprintf_s(fp, "%.10f\t", t_current);
	for (uint i = 0; i < num_body; i++) {
		fprintf_s(fp, "%.10f\t%.10f\t%.10f\t", body[i].qi, body[i].qi_dot, body[i].qi_ddot);
	}
	fprintf_s(fp, "\n");
}
void Pendulum::ludcmp(double *a, int n, uint* indx, double d, double* fac)
{
	int i, imax, j, k;
	double big, temp;
	double *vv = new double[n];
	for (i = 0; i < n; i++) {
		big = 0.0;
		for (j = 0; j < n; j++)
			if ((temp = fabs(a[i*n+j])) > big) big = temp;
		if (big == 0.0) {
			printf("Singular matrix in LUdcmp");
		}
		vv[i] = 1.0 / big;
	}
	for (k = 0; k < n; k++) {
		big = 0.0;
		for (i = k; i < n; i++) {
			temp = vv[i] * fabs(a[i*n+k]);
			if (temp > big) {
				big = temp;
				imax = i;
			}
		}
		if (k != imax) {
			for (j = 0; j < n; j++) {
				temp = a[imax*n+j];
				a[imax*n+j] = a[k*n+j];
				a[k*n+j] = temp;
			}
			d = -d;
			vv[imax] = vv[k];
		}
		indx[k] = imax;
		if (a[k*n+k] == 0.0) a[k*n+k] = TINY;
		for (i = k + 1; i < n; i++) {
			temp = a[i*n+k] /= a[k*n+k];
			for (j = k + 1; j < n; j++)
				a[i*n+j] -= temp * a[k*n+j];
		}
	}
	//////////////////
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			fac[i*n+j] = a[i*n+j];
		}
	}

	delete[] vv;
}
void Pendulum::lubksb(double *a, int n, uint* indx, double *b, double *x)
{
	int i, ii = 0, ip, j;
	double sum;
	for (i = 0; i < n; i++) x[i] = b[i];
	for (i = 0; i < n; i++) {
		ip = indx[i];
		sum = x[ip];
		x[ip] = x[i];
		if (ii != 0)
			for (j = ii - 1; j < i; j++) sum -= a[i*n+j] * x[j];
		else if (sum != 0.0)
			ii = i + 1;
		x[i] = sum;
	}
	for (i = n - 1; i >= 0; i--) {
		sum = x[i];
		for (j = i + 1; j < n; j++) sum -= a[i*n+j] * x[j];
		x[i] = sum / a[i*n+i];
	}
}
