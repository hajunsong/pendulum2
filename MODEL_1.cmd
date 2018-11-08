!
!-------------------------- Default Units for Model ---------------------------!
!
!
defaults units  &
   length = meter  &
   angle = rad  &
   force = newton  &
   mass = kg  &
   time = sec
!
defaults units  &
   coordinate_system_type = cartesian  &
   orientation_type = body313
!
!--------------------------- Model Specific Colors ----------------------------!
!
!
if condition = (! db_exists(".colors.COLOR_R255G246B247"))
!
color create  &
   color_name = .colors.COLOR_R255G246B247  &
   red_component = 1.0  &
   blue_component = 0.9725490196  &
   green_component = 0.968627451
!
else 
!
color modify  &
   color_name = .colors.COLOR_R255G246B247  &
   red_component = 1.0  &
   blue_component = 0.9725490196  &
   green_component = 0.968627451
!
end 
!
if condition = (! db_exists(".colors.COLOR_R190G255B175"))
!
color create  &
   color_name = .colors.COLOR_R190G255B175  &
   red_component = 0.7490196078  &
   blue_component = 0.6862745098  &
   green_component = 1.0
!
else 
!
color modify  &
   color_name = .colors.COLOR_R190G255B175  &
   red_component = 0.7490196078  &
   blue_component = 0.6862745098  &
   green_component = 1.0
!
end 
!
if condition = (! db_exists(".colors.COLOR_R255G186B159"))
!
color create  &
   color_name = .colors.COLOR_R255G186B159  &
   red_component = 1.0  &
   blue_component = 0.6235294118  &
   green_component = 0.7333333333
!
else 
!
color modify  &
   color_name = .colors.COLOR_R255G186B159  &
   red_component = 1.0  &
   blue_component = 0.6235294118  &
   green_component = 0.7333333333
!
end 
!
if condition = (! db_exists(".colors.COLOR_R243G223B255"))
!
color create  &
   color_name = .colors.COLOR_R243G223B255  &
   red_component = 0.9568627451  &
   blue_component = 1.0  &
   green_component = 0.8745098039
!
else 
!
color modify  &
   color_name = .colors.COLOR_R243G223B255  &
   red_component = 0.9568627451  &
   blue_component = 1.0  &
   green_component = 0.8745098039
!
end 
!
!------------------------ Default Attributes for Model ------------------------!
!
!
defaults attributes  &
   inheritance = bottom_up  &
   icon_visibility = on  &
   grid_visibility = off  &
   size_of_icons = 5.0E-002  &
   spacing_for_grid = 1.0
!
!------------------------------ Adams/View Model ------------------------------!
!
!
model create  &
   model_name = MODEL_1
!
view erase
!
!--------------------------------- Materials ----------------------------------!
!
!
material create  &
   material_name = .MODEL_1.steel  &
   adams_id = 1  &
   density = 7801.0  &
   youngs_modulus = 2.07E+011  &
   poissons_ratio = 0.29
!
!-------------------------------- Rigid Parts ---------------------------------!
!
! Create parts and their dependent markers and graphics
!
!----------------------------------- ground -----------------------------------!
!
!
! ****** Ground Part ******
!
defaults model  &
   part_name = ground
!
defaults coordinate_system  &
   default_coordinate_system = .MODEL_1.ground
!
! ****** Markers for current part ******
!
marker create  &
   marker_name = .MODEL_1.ground.origin  &
   adams_id = 1  &
   location = 0.0, 0.0, 0.0  &
   orientation = 0.0, 0.0, 0.0
!
marker create  &
   marker_name = .MODEL_1.ground.MARKER_11  &
   adams_id = 11  &
   location = -1.2606181693E-005, 7.0468655311E-004, 9.8114088257E-002  &
   orientation = 3.1415926536, 1.5707963268, 3.1415926536
!
part create rigid_body mass_properties  &
   part_name = .MODEL_1.ground  &
   material_type = .MODEL_1.steel
!
part attributes  &
   part_name = .MODEL_1.ground  &
   name_visibility = off
!
!----------------------------------- body4 ------------------------------------!
!
!
defaults coordinate_system  &
   default_coordinate_system = .MODEL_1.ground
!
part create rigid_body name_and_position  &
   part_name = .MODEL_1.body4  &
   adams_id = 11  &
   location = 0.0, 0.0, 0.0  &
   orientation = 0.0, 0.0, 0.0
!
defaults coordinate_system  &
   default_coordinate_system = .MODEL_1.body4
!
! ****** Markers for current part ******
!
marker create  &
   marker_name = .MODEL_1.body4.ref  &
   adams_id = 9  &
   location = 0.0, -0.1036, 0.752  &
   orientation = 0.0, 1.5707963268, 0.0
!
marker create  &
   marker_name = .MODEL_1.body4.cm  &
   adams_id = 34  &
   location = 0.0, -0.1186, 0.752  &
   orientation = 1.5707963268, 1.5707963268, 0.0
!
marker create  &
   marker_name = .MODEL_1.body4.MARKER_19  &
   adams_id = 19  &
   location = 0.0, -0.1036, 0.752  &
   orientation = 0.0, 1.5707963268, 0.0
!
marker create  &
   marker_name = .MODEL_1.body4.end_point  &
   adams_id = 35  &
   location = 0.0, -0.1336, 0.752  &
   orientation = 0.0, 1.5707963268, 0.0
!
part create rigid_body mass_properties  &
   part_name = .MODEL_1.body4  &
   mass = 1.0E-003  &
   center_of_mass_marker = .MODEL_1.body4.cm  &
   ixx = 2.9776690613E-004  &
   iyy = 1.9851127075E-004  &
   izz = 1.9851127075E-004  &
   ixy = 0.0  &
   izx = 0.0  &
   iyz = 0.0
!
! ****** Graphics for current part ******
!
geometry create shape cylinder  &
   cylinder_name = .MODEL_1.body4.CYLINDER_15  &
   adams_id = 15  &
   center_marker = .MODEL_1.body4.ref  &
   angle_extent = 6.2831853072  &
   length = 3.0E-002  &
   radius = 3.0E-002  &
   side_count_for_body = 20  &
   segment_count_for_ends = 20
!
part attributes  &
   part_name = .MODEL_1.body4  &
   color = GREEN  &
   name_visibility = off
!
!------------------------------------ base ------------------------------------!
!
!
defaults coordinate_system  &
   default_coordinate_system = .MODEL_1.ground
!
part create rigid_body name_and_position  &
   part_name = .MODEL_1.base  &
   adams_id = 3  &
   location = 0.0, 0.0, 0.0  &
   orientation = 0.0, 0.0, 0.0
!
defaults coordinate_system  &
   default_coordinate_system = .MODEL_1.base
!
! ****** Markers for current part ******
!
marker create  &
   marker_name = .MODEL_1.base.PSMAR1  &
   adams_id = 22  &
   location = 0.0, 0.0, 0.0  &
   orientation = 0.0, 0.0, 0.0
!
marker attributes  &
   marker_name = .MODEL_1.base.PSMAR1  &
   visibility = off
!
marker create  &
   marker_name = .MODEL_1.base.PSMAR  &
   adams_id = 20  &
   location = 0.0, 0.0, 0.0  &
   orientation = 0.0, 0.0, 0.0
!
marker attributes  &
   marker_name = .MODEL_1.base.PSMAR  &
   visibility = off
!
marker create  &
   marker_name = .MODEL_1.base.cm  &
   adams_id = 21  &
   location = -1.2606181693E-005, 7.0468655311E-004, 9.8114088257E-002  &
   orientation = 3.1635129245, 3.1130397978, 1.5760529762
!
marker create  &
   marker_name = .MODEL_1.base.joint_ref  &
   adams_id = 2  &
   location = 0.0, 0.0, 0.179  &
   orientation = 0.0, 0.0, 0.0
!
marker create  &
   marker_name = .MODEL_1.base.MARKER_10  &
   adams_id = 10  &
   location = -1.2606181693E-005, 7.0468655311E-004, 9.8114088257E-002  &
   orientation = 3.1415926536, 1.5707963268, 3.1415926536
!
marker create  &
   marker_name = .MODEL_1.base.MARKER_13  &
   adams_id = 13  &
   location = 0.0, 0.0, 0.179  &
   orientation = 0.0, 0.0, 0.0
!
part create rigid_body mass_properties  &
   part_name = .MODEL_1.base  &
   density = 2700.0
!
! ****** Graphics for current part ******
!
part attributes  &
   part_name = .MODEL_1.base  &
   color = COLOR_R255G246B247
!
!----------------------------------- body1 ------------------------------------!
!
!
defaults coordinate_system  &
   default_coordinate_system = .MODEL_1.ground
!
part create rigid_body name_and_position  &
   part_name = .MODEL_1.body1  &
   adams_id = 4  &
   location = 0.0, 0.0, 0.0  &
   orientation = 0.0, 0.0, 0.0
!
defaults coordinate_system  &
   default_coordinate_system = .MODEL_1.body1
!
! ****** Markers for current part ******
!
marker create  &
   marker_name = .MODEL_1.body1.PSMAR  &
   adams_id = 23  &
   location = 0.0, 0.0, 0.0  &
   orientation = 0.0, 0.0, 0.0
!
marker attributes  &
   marker_name = .MODEL_1.body1.PSMAR  &
   visibility = off
!
marker create  &
   marker_name = .MODEL_1.body1.PSMAR1  &
   adams_id = 25  &
   location = 0.0, 0.0, 0.0  &
   orientation = 0.0, 0.0, 0.0
!
marker attributes  &
   marker_name = .MODEL_1.body1.PSMAR1  &
   visibility = off
!
marker create  &
   marker_name = .MODEL_1.body1.cm  &
   adams_id = 24  &
   location = 1.6400029422E-002, -1.4726955847E-007, 0.2414183687  &
   orientation = 1.5707827405, 1.3157379473, 6.2831554115
!
marker create  &
   marker_name = .MODEL_1.body1.ref  &
   adams_id = 3  &
   location = 0.0, 0.0, 0.179  &
   orientation = 0.0, 0.0, 0.0
!
marker create  &
   marker_name = .MODEL_1.body1.joint_ref  &
   adams_id = 4  &
   location = -4.4E-002, 0.0, 0.252  &
   orientation = 1.5707963268, 1.5707963268, 0.0
!
marker create  &
   marker_name = .MODEL_1.body1.MARKER_12  &
   adams_id = 12  &
   location = 0.0, 0.0, 0.179  &
   orientation = 0.0, 0.0, 0.0
!
marker create  &
   marker_name = .MODEL_1.body1.MARKER_14  &
   adams_id = 14  &
   location = -4.4E-002, 0.0, 0.252  &
   orientation = 1.5707963268, 1.5707963268, 4.7123889804
!
part create rigid_body mass_properties  &
   part_name = .MODEL_1.body1  &
   density = 2700.0
!
! ****** Graphics for current part ******
!
part attributes  &
   part_name = .MODEL_1.body1  &
   color = COLOR_R190G255B175
!
!----------------------------------- body3 ------------------------------------!
!
!
defaults coordinate_system  &
   default_coordinate_system = .MODEL_1.ground
!
part create rigid_body name_and_position  &
   part_name = .MODEL_1.body3  &
   adams_id = 6  &
   location = 0.0, 0.0, 0.0  &
   orientation = 0.0, 0.0, 0.0
!
defaults coordinate_system  &
   default_coordinate_system = .MODEL_1.body3
!
! ****** Markers for current part ******
!
marker create  &
   marker_name = .MODEL_1.body3.PSMAR1  &
   adams_id = 31  &
   location = 0.0, 0.0, 0.0  &
   orientation = 0.0, 0.0, 0.0
!
marker attributes  &
   marker_name = .MODEL_1.body3.PSMAR1  &
   visibility = off
!
marker create  &
   marker_name = .MODEL_1.body3.PSMAR  &
   adams_id = 26  &
   location = 0.0, 0.0, 0.0  &
   orientation = 0.0, 0.0, 0.0
!
marker attributes  &
   marker_name = .MODEL_1.body3.PSMAR  &
   visibility = off
!
marker create  &
   marker_name = .MODEL_1.body3.PSMAR2  &
   adams_id = 30  &
   location = 0.0, 0.0, 0.0  &
   orientation = 0.0, 0.0, 0.0
!
marker attributes  &
   marker_name = .MODEL_1.body3.PSMAR2  &
   visibility = off
!
marker create  &
   marker_name = .MODEL_1.body3.PSMAR4  &
   adams_id = 28  &
   location = 0.0, 0.0, 0.0  &
   orientation = 0.0, 0.0, 0.0
!
marker attributes  &
   marker_name = .MODEL_1.body3.PSMAR4  &
   visibility = off
!
marker create  &
   marker_name = .MODEL_1.body3.PSMAR3  &
   adams_id = 29  &
   location = 0.0, 0.0, 0.0  &
   orientation = 0.0, 0.0, 0.0
!
marker attributes  &
   marker_name = .MODEL_1.body3.PSMAR3  &
   visibility = off
!
marker create  &
   marker_name = .MODEL_1.body3.cm  &
   adams_id = 27  &
   location = 7.742274065E-003, -7.7429032998E-003, 0.6270000069  &
   orientation = 5.4977752865, 0.1111014242, 1.5716838181
!
marker create  &
   marker_name = .MODEL_1.body3.ref  &
   adams_id = 7  &
   location = -4.4E-002, 0.0, 0.502  &
   orientation = 1.5707963268, 1.5707963268, 0.0
!
marker create  &
   marker_name = .MODEL_1.body3.joint_ref  &
   adams_id = 8  &
   location = 0.0, -0.1036, 0.752  &
   orientation = 0.0, 1.5707963268, 0.0
!
marker create  &
   marker_name = .MODEL_1.body3.MARKER_17  &
   adams_id = 17  &
   location = -4.4E-002, 0.0, 0.502  &
   orientation = 1.5707963268, 1.5707963268, 4.7123889804
!
marker create  &
   marker_name = .MODEL_1.body3.MARKER_18  &
   adams_id = 18  &
   location = 0.0, -0.1036, 0.752  &
   orientation = 0.0, 1.5707963268, 0.0
!
part create rigid_body mass_properties  &
   part_name = .MODEL_1.body3  &
   density = 2700.0
!
! ****** Graphics for current part ******
!
part attributes  &
   part_name = .MODEL_1.body3  &
   color = COLOR_R255G186B159
!
!----------------------------------- body2 ------------------------------------!
!
!
defaults coordinate_system  &
   default_coordinate_system = .MODEL_1.ground
!
part create rigid_body name_and_position  &
   part_name = .MODEL_1.body2  &
   adams_id = 10  &
   location = 0.0, 0.0, 0.0  &
   orientation = 0.0, 0.0, 0.0
!
defaults coordinate_system  &
   default_coordinate_system = .MODEL_1.body2
!
! ****** Markers for current part ******
!
marker create  &
   marker_name = .MODEL_1.body2.PSMAR  &
   adams_id = 32  &
   location = 0.0, 0.0, 0.0  &
   orientation = 0.0, 0.0, 0.0
!
marker attributes  &
   marker_name = .MODEL_1.body2.PSMAR  &
   visibility = off
!
marker create  &
   marker_name = .MODEL_1.body2.ref  &
   adams_id = 5  &
   location = -4.4E-002, 0.0, 0.252  &
   orientation = 1.5707963268, 1.5707963268, 0.0
!
marker create  &
   marker_name = .MODEL_1.body2.cm  &
   adams_id = 33  &
   location = -6.4091982318E-002, -5.410667759E-005, 0.377  &
   orientation = 6.2823072834, 0.0, 0.0
!
marker create  &
   marker_name = .MODEL_1.body2.joint_ref  &
   adams_id = 6  &
   location = -4.4E-002, 0.0, 0.502  &
   orientation = 1.5707963268, 1.5707963268, 0.0
!
marker create  &
   marker_name = .MODEL_1.body2.MARKER_15  &
   adams_id = 15  &
   location = -4.4E-002, 0.0, 0.252  &
   orientation = 1.5707963268, 1.5707963268, 4.7123889804
!
marker create  &
   marker_name = .MODEL_1.body2.MARKER_16  &
   adams_id = 16  &
   location = -4.4E-002, 0.0, 0.502  &
   orientation = 1.5707963268, 1.5707963268, 4.7123889804
!
part create rigid_body mass_properties  &
   part_name = .MODEL_1.body2  &
   density = 2700.0
!
! ****** Graphics for current part ******
!
part attributes  &
   part_name = .MODEL_1.body2  &
   color = COLOR_R243G223B255
!
! ****** Graphics from Parasolid file ******
!
file parasolid read  &
   file_name = "MODEL_1.xmt_txt"  &
   model_name = .MODEL_1
!
geometry attributes  &
   geometry_name = .MODEL_1.base.SOLID2  &
   color = COLOR_R255G246B247
!
geometry attributes  &
   geometry_name = .MODEL_1.base.SOLID1  &
   color = COLOR_R255G246B247
!
geometry attributes  &
   geometry_name = .MODEL_1.body1.SOLID3  &
   color = COLOR_R190G255B175
!
geometry attributes  &
   geometry_name = .MODEL_1.body1.SOLID6  &
   color = COLOR_R190G255B175
!
geometry attributes  &
   geometry_name = .MODEL_1.body3.SOLID5  &
   color = COLOR_R255G186B159
!
geometry attributes  &
   geometry_name = .MODEL_1.body3.SOLID8  &
   color = COLOR_R255G186B159
!
geometry attributes  &
   geometry_name = .MODEL_1.body3.SOLID10  &
   color = COLOR_R255G186B159
!
geometry attributes  &
   geometry_name = .MODEL_1.body3.SOLID7  &
   color = COLOR_R255G186B159
!
geometry attributes  &
   geometry_name = .MODEL_1.body3.SOLID4  &
   color = COLOR_R255G186B159
!
geometry attributes  &
   geometry_name = .MODEL_1.body2.SOLID9  &
   color = COLOR_R243G223B255
!
!----------------------------------- Joints -----------------------------------!
!
!
constraint create joint fixed  &
   joint_name = .MODEL_1.JOINT_1  &
   adams_id = 1  &
   i_marker_name = .MODEL_1.base.MARKER_10  &
   j_marker_name = .MODEL_1.ground.MARKER_11
!
constraint attributes  &
   constraint_name = .MODEL_1.JOINT_1  &
   name_visibility = off
!
constraint create joint revolute  &
   joint_name = .MODEL_1.JOINT_2  &
   adams_id = 2  &
   i_marker_name = .MODEL_1.body1.MARKER_12  &
   j_marker_name = .MODEL_1.base.MARKER_13  &
   rotational_ic = 0.0  &
   angular_velocity_ic = 1.745329252
!
constraint attributes  &
   constraint_name = .MODEL_1.JOINT_2  &
   name_visibility = off
!
constraint create joint revolute  &
   joint_name = .MODEL_1.JOINT_3  &
   adams_id = 3  &
   i_marker_name = .MODEL_1.body1.MARKER_14  &
   j_marker_name = .MODEL_1.body2.MARKER_15
!
constraint attributes  &
   constraint_name = .MODEL_1.JOINT_3  &
   name_visibility = off
!
constraint create joint revolute  &
   joint_name = .MODEL_1.JOINT_4  &
   adams_id = 4  &
   i_marker_name = .MODEL_1.body2.MARKER_16  &
   j_marker_name = .MODEL_1.body3.MARKER_17
!
constraint attributes  &
   constraint_name = .MODEL_1.JOINT_4  &
   name_visibility = off
!
constraint create joint revolute  &
   joint_name = .MODEL_1.JOINT_5  &
   adams_id = 5  &
   i_marker_name = .MODEL_1.body3.MARKER_18  &
   j_marker_name = .MODEL_1.body4.MARKER_19  &
   rotational_ic = 0.0  &
   angular_velocity_ic = -1.745329252
!
constraint attributes  &
   constraint_name = .MODEL_1.JOINT_5  &
   name_visibility = off
!
!----------------------------------- Forces -----------------------------------!
!
!
!----------------------------- Simulation Scripts -----------------------------!
!
!
simulation script create  &
   sim_script_name = .MODEL_1.Last_Sim  &
   commands =   &
              "simulation single_run transient type=auto_select initial_static=no end_time=0.45 step_size=1.0E-003 model_name=.MODEL_1"
!
!---------------------------------- Accgrav -----------------------------------!
!
!
force create body gravitational  &
   gravity_field_name = gravity  &
   x_component_gravity = 0.0  &
   y_component_gravity = 0.0  &
   z_component_gravity = -9.80665
!
!----------------------------- Analysis settings ------------------------------!
!
!
executive_control set numerical_integration_parameters  &
   model_name = MODEL_1  &
   integrator_type = wstiff
!
!---------------------------------- Measures ----------------------------------!
!
!
measure create point  &
   measure_name = .MODEL_1.end_point_x  &
   point = .MODEL_1.body4.end_point  &
   characteristic = translational_displacement  &
   component = x_component  &
   create_measure_display = no
!
data_element attributes  &
   data_element_name = .MODEL_1.end_point_x  &
   color = WHITE
!
measure create point  &
   measure_name = .MODEL_1.end_point_y  &
   point = .MODEL_1.body4.end_point  &
   characteristic = translational_displacement  &
   component = y_component  &
   create_measure_display = no
!
data_element attributes  &
   data_element_name = .MODEL_1.end_point_y  &
   color = WHITE
!
measure create point  &
   measure_name = .MODEL_1.end_point_z  &
   point = .MODEL_1.body4.end_point  &
   characteristic = translational_displacement  &
   component = z_component  &
   create_measure_display = no
!
data_element attributes  &
   data_element_name = .MODEL_1.end_point_z  &
   color = WHITE
!
measure create function  &
   measure_name = .MODEL_1.q1  &
   function = ""  &
   units = "angle"  &
   create_measure_display = no
!
data_element attributes  &
   data_element_name = .MODEL_1.q1  &
   color = WHITE
!
measure create function  &
   measure_name = .MODEL_1.q2  &
   function = ""  &
   units = "angle"  &
   create_measure_display = no
!
data_element attributes  &
   data_element_name = .MODEL_1.q2  &
   color = WHITE
!
measure create function  &
   measure_name = .MODEL_1.q3  &
   function = ""  &
   units = "angle"  &
   create_measure_display = no
!
data_element attributes  &
   data_element_name = .MODEL_1.q3  &
   color = WHITE
!
measure create function  &
   measure_name = .MODEL_1.q4  &
   function = ""  &
   units = "angle"  &
   create_measure_display = no
!
data_element attributes  &
   data_element_name = .MODEL_1.q4  &
   color = WHITE
!
measure create function  &
   measure_name = .MODEL_1.q4_dot  &
   function = ""  &
   units = "angular_velocity"  &
   create_measure_display = no
!
data_element attributes  &
   data_element_name = .MODEL_1.q4_dot  &
   color = WHITE
!
measure create function  &
   measure_name = .MODEL_1.q1_ddot  &
   function = ""  &
   units = "angular_acceleration"  &
   create_measure_display = no
!
data_element attributes  &
   data_element_name = .MODEL_1.q1_ddot  &
   color = WHITE
!
measure create function  &
   measure_name = .MODEL_1.q2_ddot  &
   function = ""  &
   units = "angular_acceleration"  &
   create_measure_display = no
!
data_element attributes  &
   data_element_name = .MODEL_1.q2_ddot  &
   color = WHITE
!
measure create function  &
   measure_name = .MODEL_1.q3_ddot  &
   function = ""  &
   units = "angular_acceleration"  &
   create_measure_display = no
!
data_element attributes  &
   data_element_name = .MODEL_1.q3_ddot  &
   color = WHITE
!
measure create function  &
   measure_name = .MODEL_1.q1_dot  &
   function = ""  &
   units = "angular_velocity"  &
   create_measure_display = no
!
data_element attributes  &
   data_element_name = .MODEL_1.q1_dot  &
   color = WHITE
!
measure create function  &
   measure_name = .MODEL_1.q2_dot  &
   function = ""  &
   units = "angular_velocity"  &
   create_measure_display = no
!
data_element attributes  &
   data_element_name = .MODEL_1.q2_dot  &
   color = WHITE
!
measure create function  &
   measure_name = .MODEL_1.q3_dot  &
   function = ""  &
   units = "angular_velocity"  &
   create_measure_display = no
!
data_element attributes  &
   data_element_name = .MODEL_1.q3_dot  &
   color = WHITE
!
measure create function  &
   measure_name = .MODEL_1.q4_ddot  &
   function = ""  &
   units = "angular_acceleration"  &
   create_measure_display = no
!
data_element attributes  &
   data_element_name = .MODEL_1.q4_ddot  &
   color = WHITE
!
!---------------------------- Function definitions ----------------------------!
!
!
measure modify function  &
   measure_name = .MODEL_1.q1  &
   function = "AZ(.MODEL_1.body1.ref, .MODEL_1.base.joint_ref)"
!
measure modify function  &
   measure_name = .MODEL_1.q2  &
   function = "AZ(.MODEL_1.body2.ref, .MODEL_1.body1.joint_ref)"
!
measure modify function  &
   measure_name = .MODEL_1.q3  &
   function = "AZ(.MODEL_1.body3.ref, .MODEL_1.body2.joint_ref)"
!
measure modify function  &
   measure_name = .MODEL_1.q4  &
   function = "AZ(.MODEL_1.body4.ref, .MODEL_1.body3.joint_ref)"
!
measure modify function  &
   measure_name = .MODEL_1.q4_dot  &
   function = "WZ(.MODEL_1.body4.ref, .MODEL_1.body3.joint_ref, .MODEL_1.body3.joint_ref)"
!
measure modify function  &
   measure_name = .MODEL_1.q1_ddot  &
   function = "WDTZ(.MODEL_1.body1.ref, .MODEL_1.base.joint_ref, .MODEL_1.base.joint_ref, .MODEL_1.base.joint_ref)"
!
measure modify function  &
   measure_name = .MODEL_1.q2_ddot  &
   function = "WDTZ(.MODEL_1.body2.ref, .MODEL_1.body1.joint_ref, .MODEL_1.body1.joint_ref, .MODEL_1.body1.joint_ref)"
!
measure modify function  &
   measure_name = .MODEL_1.q3_ddot  &
   function = "WDTZ(.MODEL_1.body3.ref, .MODEL_1.body2.joint_ref, .MODEL_1.body2.joint_ref, .MODEL_1.body2.joint_ref)"
!
measure modify function  &
   measure_name = .MODEL_1.q1_dot  &
   function = "WZ(.MODEL_1.body1.ref, .MODEL_1.base.joint_ref, .MODEL_1.base.joint_ref)"
!
measure modify function  &
   measure_name = .MODEL_1.q2_dot  &
   function = "WZ(.MODEL_1.body2.ref, .MODEL_1.body1.joint_ref, .MODEL_1.body1.joint_ref)"
!
measure modify function  &
   measure_name = .MODEL_1.q3_dot  &
   function = "WZ(.MODEL_1.body3.ref, .MODEL_1.body2.joint_ref, .MODEL_1.body2.joint_ref)"
!
measure modify function  &
   measure_name = .MODEL_1.q4_ddot  &
   function = "WDTZ(.MODEL_1.body4.ref, .MODEL_1.body3.joint_ref, .MODEL_1.body3.joint_ref, .MODEL_1.body3.joint_ref)"
!
!--------------------------- Expression definitions ---------------------------!
!
!
defaults coordinate_system  &
   default_coordinate_system = ground
!
marker modify  &
   marker_name = .MODEL_1.body2.ref  &
   orientation =   &
      (ORI_RELATIVE_TO({0, 0, 0}, .MODEL_1.body1.joint_ref))  &
   relative_to = .MODEL_1.body2
!
defaults coordinate_system  &
   default_coordinate_system = .MODEL_1.ground
!
marker modify  &
   marker_name = .MODEL_1.body4.ref  &
   location =   &
      (LOC_RELATIVE_TO({0, 0, 0}, .MODEL_1.body3.joint_ref))  &
   orientation =   &
      (ORI_RELATIVE_TO({0, 0, 0}, .MODEL_1.body3.joint_ref))  &
   relative_to = .MODEL_1.body4
!
defaults coordinate_system  &
   default_coordinate_system = .MODEL_1.ground
!
geometry modify shape cylinder  &
   cylinder_name = .MODEL_1.body4.CYLINDER_15  &
   length = (3.0E-002meter)  &
   radius = (3.0E-002meter)
!
marker modify  &
   marker_name = .MODEL_1.body4.end_point  &
   location =   &
      (LOC_RELATIVE_TO({0, 0, 3.0E-002meter}, .MODEL_1.body4.ref))  &
   orientation =   &
      (ORI_RELATIVE_TO({0, 0, 0}, .MODEL_1.body4.ref))  &
   relative_to = .MODEL_1.body4
!
defaults coordinate_system  &
   default_coordinate_system = .MODEL_1.ground
!
material modify  &
   material_name = .MODEL_1.steel  &
   density = (7801.0(kg/meter**3))  &
   youngs_modulus = (2.07E+011(Newton/meter**2))
!
model display  &
   model_name = MODEL_1
