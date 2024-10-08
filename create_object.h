#pragma once
#include "initVariables.h"
inline int subdiv1=32;
inline int subdiv2=32;

inline void copy_material(const materialType *sorc, materialType *mat){

    mat->matEnable=sorc->matEnable;
    mat->smooth=sorc->smooth;

    mat->color[0]=sorc->color[0];
    mat->color[1]=sorc->color[1];
    mat->color[2]=sorc->color[2];
    mat->color[3]=sorc->color[3];

    mat->mat_ambient[0]=sorc->mat_ambient[0];
    mat->mat_ambient[1]=sorc->mat_ambient[1];
    mat->mat_ambient[2]=sorc->mat_ambient[2];
    mat->mat_ambient[3]=sorc->mat_ambient[3];

    mat->mat_diffuse[0]=sorc->mat_diffuse[0];
    mat->mat_diffuse[1]=sorc->mat_diffuse[1];
    mat->mat_diffuse[2]=sorc->mat_diffuse[2];
    mat->mat_diffuse[3]=sorc->mat_diffuse[3];

    mat->mat_specular[0]=sorc->mat_specular[0];
    mat->mat_specular[1]=sorc->mat_specular[1];
    mat->mat_specular[2]=sorc->mat_specular[2];
    mat->mat_specular[3]=sorc->mat_specular[3];

    mat->mat_shininess=sorc->mat_shininess;
}

// assign Material
inline void assign_material(materialType *mat){

    if(mat == nullptr) {
        return;
    }

    mat->matEnable=1;
    mat->smooth=GL_SMOOTH;
    mat->texture=NULL;

    mat->color[0]=static_cast<GLfloat>(rand() % 100)/100;
    mat->color[1]=static_cast<GLfloat>(rand() % 100)/100;
    mat->color[2]=static_cast<GLfloat>(rand() % 100)/100;
    mat->color[3]=1.0f;

    mat->mat_ambient[0]=0.7f;
    mat->mat_ambient[1]=0.7f;
    mat->mat_ambient[2]=0.7f;
    mat->mat_ambient[3]=1.0f;

    mat->mat_diffuse[0]=0.8f;
    mat->mat_diffuse[1]=0.8f;
    mat->mat_diffuse[2]=0.8f;
    mat->mat_diffuse[3]=1.0f;

    mat->mat_specular[0]=1.0f;
    mat->mat_specular[1]=1.0f;
    mat->mat_specular[2]=1.0f;
    mat->mat_specular[3]=1.0f;

    mat->mat_shininess=100.0f;

    LoadGLTextures(mat->texture);
}

inline void copy_object(struct object *sorc, struct object *target,int serial_no){
    target->serial_no=serial_no;
    target->type=sorc->type;

    target->position[0]=sorc->position[0];
    target->position[1]=sorc->position[1];
    target->position[2]=sorc->position[2];

    target->rotation[0]=sorc->rotation[0];
    target->rotation[1]=sorc->rotation[1];
    target->rotation[2]=sorc->rotation[2];


    target->scale[0]=sorc->scale[0];
    target->scale[1]=sorc->scale[1];
    target->scale[2]=sorc->scale[2];

    target->variables[0]=sorc->variables[0];
    target->variables[1]=sorc->variables[1];
    target->variables[2]=sorc->variables[2];
    target->variables[3]=sorc->variables[3];

    target->next=NULL;

    target->mat=(struct materialType*)malloc(sizeof(struct materialType));
    copy_material(sorc->mat,target->mat);
}

// Initializing Data Structure for 3d-Objects
void create_object(struct object *place, int type, int serial_no){

    place->serial_no=serial_no;
    place->type=type;

    place->position[0]=0.0f;
    place->position[1]=0.0f;
    place->position[2]=0.0f;

    place->rotation[0]=0;
    place->rotation[1]=0;
    place->rotation[2]=0;


    place->scale[0]=1.0f;
    place->scale[1]=1.0f;
    place->scale[2]=1.0f;

    if(place->type==1){
        place->variables[0]=1*scale_factor_local;
        place->variables[1]=2*scale_factor_local;
        place->variables[2]=1*scale_factor_local;
    }
    else if(place->type==2){
        place->variables[0]=1*scale_factor_local;
        place->variables[1]=subdiv1;
        place->variables[2]=subdiv2;
    }
    else if(place->type==3){
        place->variables[0]=1.0*scale_factor_local;
        place->variables[1]=2.0*scale_factor_local;
        place->variables[2]=subdiv1;
        place->variables[3]=subdiv2;
    }
    else if(place->type==4){
        place->variables[0]=0.4*scale_factor_local;
        place->variables[1]=1*scale_factor_local;
        place->variables[2]=subdiv1;
        place->variables[3]=subdiv2;
    }
    else if(place->type==5){
        place->variables[0]=0.5*scale_factor_local;
        place->variables[1]=2.0*scale_factor_local;
        place->variables[2]=subdiv1;
        place->variables[3]=subdiv2;
    }
    else if(place->type==6){
        place->variables[0]=2*scale_factor_local;
        place->variables[1]=4*scale_factor_local;
        place->variables[2]=4;
        place->variables[3]=4;
    }
    else if(place->type==7){
        place->variables[0]=1*scale_factor_local;
    }

    place->next=nullptr;

    place->mat=static_cast<materialType *>(malloc(sizeof(materialType)));
    assign_material(place->mat);
}
//1->box, 2->sphere, 3->cone, 4->torus, 5->teapot, 6->plane

// Initializing DataStructure for Camera
inline void create_camera(struct camera *cam){

    cam->radius=2000.0;

    cam->center[0]=0.0f;
    cam->center[1]=0.0f;
    cam->center[2]=0.0f;

    cam->sideAngle=45.0f;
    cam->upAngle=60.0f;

    cam->up[0]=0.0f;
    cam->up[1]=1.0f;
    cam->up[2]=0.0f;
}

// Initializing DataStructure for lights
inline void create_light(struct light *lght, int i){

    lght->on=0;
    lght->number=i;

    // ambient values
    lght->light_ambient[0] = 0.2f;
    lght->light_ambient[1] = 0.2f;
    lght->light_ambient[2] = 0.2f;
    lght->light_ambient[3] = 0.0f;

    // diffuse values
    lght->light_diffuse[0] = 1.0f;
    lght->light_diffuse[1] = 1.0f;
    lght->light_diffuse[2] = 1.0f;
    lght->light_diffuse[3] = 1.0f;

    //specular values
    lght->light_specular[0] = 1.0f;
    lght->light_specular[1] = 1.0f;
    lght->light_specular[2] = 1.0f;
    lght->light_specular[3] = 1.0f;

    // position values
    if(i==0){
        lght->light_position[0] = 10.0*scale_factor_local;
        lght->light_position[1] = 5.0*scale_factor_local;
        lght->light_position[2] = 10.0*scale_factor_local;
        lght->light_position[3] = 1.0f;
    }
    else{
        lght->light_position[0] = 5.0*scale_factor_local;
        lght->light_position[1] = 5.0*scale_factor_local;
        lght->light_position[2] = 5.0*scale_factor_local;
        lght->light_position[3] = 1.0f;
    }

    lght->light_attenuation[0]=0;
    lght->light_attenuation[1]=0.5f;

}

inline void create_particle(struct particle * par,int type){

    GLfloat angl=static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/30))*M_PI/180;
    GLfloat hangl=2*M_PI*static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/180));
    GLfloat rad=static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/0.01));

    par->position[0]=rad*cos((GLfloat)hangl);
    par->position[1]=0;
    par->position[2]=rad*sin((GLfloat)hangl);

    //par->velocity[1]=static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/30));
    par->velocity[0]=1*cos((GLfloat)angl)*cos((GLfloat)hangl);
    par->velocity[1]=1+15*sin((GLfloat)angl);
    par->velocity[2]=1*cos((GLfloat)angl)*sin((GLfloat)hangl);

}

inline void create_emittor(struct emittor *emt, int type){
    emt->type=type;
    emt->on=1;
    emt->parCount=5000;

    emt->time=0.05;

    emt->position[0]=0;
    emt->position[1]=0;
    emt->position[2]=0;

    emt->velocity[0]=0;
    emt->velocity[1]=20;
    emt->velocity[2]=0;

    struct particle *temp;
    temp=static_cast<particle *>(malloc(sizeof(particle)));
    emt->par=temp;
    for(int i=1;i<emt->parCount;i++){
        create_particle(temp,type);
        temp->next=static_cast<particle *>(malloc(sizeof(particle)));
        temp=temp->next;
    }
}



