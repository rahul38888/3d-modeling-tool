#pragma once
inline float scale_factor_local=100;
inline float cam_scale=100;

#define PI 3.14159

#define SHRINK 1
#define NORMAL 2

inline GLuint textureId;

inline char select_type;

inline object *temp;

inline int fillMenu, shrinkMenu, mainMenu, lightMenu, bezierType, fileMenu;

/*Camera Atributes*/
inline camera *cam=static_cast<struct camera *>(malloc(sizeof(struct camera)));

inline object *head;
inline object *tail;
inline object *selected;

inline emittor *emm;

inline int selected_light;

inline light *lght[8];
inline int turn_light=0;
inline int light_no;
inline int started_light=1;

inline int new_obj=0;
inline int started=1;
inline int type=5;
inline int serial_no=-1;
inline int l0=0, l1=0;
inline int sl=-1;
inline int isWired=0;
inline int isCam=0;

inline char transTool='n';
inline char transDim='x';
inline char camMode = 'o';

inline int deltaUp=0;
inline int deltaSide=0;
inline int deltaUpMode=0;
inline int deltaSideMode=0;

inline int gridMode=1;

inline int winW=1350;
inline int winH=690;

inline int winInW=200;
inline int winInH=200;

inline int textUpLimit=580;
inline int nurb=0, bezcrv=0, parf=0;

inline int viewport;
inline int controles=0;

inline int save_on=0;
inline int load_on=0;
inline char file_name[100] = "example.3d";

inline GLenum globalSmooth=GL_SMOOTH;

inline void cameraUpdate();
inline float xy_aspect;

inline GLUI_Panel *object_type, *object_info, *save_load;
inline GLUI_Button *cube, *sphere, *cone, *torus, *cylinder, *plane, *teapot;
inline GLUI_Button *cam_dolly, *cam_truck, *cam_orbit, *confirm, *cancel;
inline GLUI_StaticText *ob_name, *ob_serial, *ob_pos, *ob_rot, *ob_scal;
inline GLUI_Panel *transform_panel, *camera, *sl_panel, *mat_panel, *color_panel, *ambient_panel, *diffuse_panel, *specular_panel;
inline GLUI_Panel *lght_panel, *amb_lght, *dif_lght, *spe_lght, *pos_lght, *att_lght, *lght_panel0, *lght_panel1;
inline GLUI_Spinner *x_axis, *y_axis, *z_axis, *var1, *var2, *var3, *var4, *shininess;
inline GLUI *glui_right, *glui_bottom, *glui_top, *glui_left, *new_win=0, *new_win1=0, *mat_win=0, *lght_win=0;
inline GLUI_Checkbox *mat_enable, *smooth;
inline GLUI_Scrollbar *color0, *color1, *color2, *color3, *ambient0, *ambient1, *ambient2, *ambient3, *diffuse0, *diffuse1, *diffuse2, *diffuse3, *specular0, *specular1, *specular2, *specular3;
inline GLUI_Scrollbar *l_amb0,  *l_amb1, *l_amb2, *l_amb3, *l_spe0, *l_spe1, *l_spe2, *l_spe3, *l_dif0, *l_dif1, *l_dif2, *l_dif3;
inline GLUI_Spinner *l_pos0, *l_pos1, *l_pos2, *l_pos3, *l_att1;
inline GLUI_Checkbox *lght_enable, *l_att0;
inline GLUI_EditText *col0, *col1, *col2, *col3, *amb0, *amb1, *amb2, *amb3, *dif0, *dif1, *dif2, *dif3, *spe0, *spe1, *spe2, *spe3;
inline GLUI_EditText *amb_10, *amb_l1, *amb_l2, *amb_l3, *dif_l0, *dif_l1, *dif_l2, *dif_l3, *spe_l0, *spe_l1, *spe_l2, *spe_l3;
inline GLUI_EditText *file_nm;
inline GLUI_FileBrowser * browse;
inline GLUI_Rollout *obj_roll;

inline float x_var, y_var, z_var, vara, varb, varc, vard, testvar=0;
inline float c0, c1, c2, c3, a0, a1, a2, a3, d0, d1, d2, d3, s0, s1, s2, s3, sn, attn;
inline int me, st;
inline int enbl;

inline int button_w=65;
inline int spinner_w=0;
inline char slmode='l';
