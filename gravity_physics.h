#pragma once
inline float g=9.8;

inline void movement(struct particle *par, const float t){
    if(par->position[1]>=0){
        par->position[0]+=t*par->velocity[0];
        par->position[1]+=t*par->velocity[1]-g*t*t/2;
        par->position[2]+=t*par->velocity[2];

        par->velocity[1]-=g*t;
    }
    else{
        create_particle(par,1);
    }
}

inline void update_fountain(const struct emittor *emm){
    particle *temp = emm->par;
    //emm->time+=0.1f;
    for(int i=0;i<emm->parCount;i++){
        movement(temp,emm->time);
        //printf("%f ", par->velocity[1]);
        temp=temp->next;
    }
}

inline void render_particle(const struct particle *par, const struct camera *cam,int type){

    if(par->velocity[1]>=0 || (par->velocity[1]<0 && par->position[1]>=0)){

    GLfloat speed = par->velocity[1];
    if(speed<0) speed=-(speed);

    if (type==1) glColor4f(speed/15,speed/8,1,1);
    else if (type==2) glColor4f(speed/1,speed/0.5,1,0.2);
    glDisable(GL_LIGHTING);
    glPushMatrix();
        glTranslatef(par->position[0],par->position[1],par->position[2]);
        glRotatef(cam->sideAngle,0,1,0);
        glRotatef(cam->upAngle,1,0,0);
        glScalef(par->position[1]/8,1,par->position[1]/8);
        GLfloat a=0.2;
        glNormal3f(0,1,0);
        glBegin(GL_QUADS);
            glVertex3f(a,0,a);
            glVertex3f(-a,0,a);
            glVertex3f(-a,0,-a);
            glVertex3f(a,0,-a);
        glEnd();
    glPopMatrix();
    glEnable(GL_LIGHTING);
    }
}

inline void render_fountain(const struct emittor *emm, const struct camera *cam){
    const struct particle *temp = emm->par;
    glPushMatrix();
        for(int i=0;i<emm->parCount;i++){
            render_particle(temp,cam,emm->type);
            temp=temp->next;
        }
    glPopMatrix();
    update_fountain(emm);
}

inline GLfloat r=2.0f;
inline GLfloat agl=0;

inline void animation(){
    GLfloat x = r * cos(agl * M_PI / 180);
    GLfloat z = r * sin(agl * M_PI / 180);

    glColor3f(0.6,0.5,0);
    glPushMatrix();
        glTranslatef(x,0,z);
        glRotatef(-agl,0,1,0);
        glRotatef(-agl,1,0,0);
        glRotatef(agl,0,0,1);
        glutSolidCube(0.5f);
    glPopMatrix();

    agl+=5.0f;
    if(agl>360) agl=agl-360;

}
