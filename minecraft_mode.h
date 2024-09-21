#pragma once
inline void drawBlockSphere(struct object *obj){
    int i, j, k;
    constexpr int n=30;
    const GLfloat a=obj->variables[0];
    const GLfloat dd=2*a/n;
    GLfloat x=a-dd/2, y=a-dd/2, z=a-dd/2;

    for(i=0,x=a-dd/2;i<n;i++,x-=dd){
        for(j=0,y=a-dd/2;j<n;j++,y-=dd){
            for(k=0,z=a-dd/2;k<n;k++,z-=dd){
                GLfloat d = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
                if(d<=a && a-dd<=d){
                    if((i+j+k)%2) glColor3f(obj->mat->color[0],obj->mat->color[1],obj->mat->color[2]);
                    else glColor3f(obj->mat->color[0],obj->mat->color[1]/2,obj->mat->color[2]/2);
                    glPushMatrix();
                        glTranslatef(x,y,z);
                        glutSolidCube(dd);
                    glPopMatrix();
                }
            }
        }
    }
}

inline void drawBlockCylinder(const struct object *obj){
    int i, j, k;
    constexpr int n=20;
    const GLfloat a=obj->variables[0];
    const GLfloat h=obj->variables[1];
    const GLfloat dd=2*a/n;
    GLfloat x=a-dd/2, y=h-dd/2, z=a-dd/2;

    for(i=0,x=a-dd/2;i<n;i++,x-=dd){
        for(j=0,y=h-dd/2;j<2*n;j++,y-=dd){
            for(k=0,z=a-dd/2;k<n;k++,z-=dd){
                GLfloat d = sqrt(pow(x, 2) + pow(z, 2));
                if((i+j+k)%2) glColor3f(obj->mat->color[0],obj->mat->color[1],obj->mat->color[2]);
                else glColor3f(obj->mat->color[0],obj->mat->color[1]/2,obj->mat->color[2]/2);
                if(d<=a && 36*a/40<=d){
                    glPushMatrix();
                        glTranslatef(x,y,z);
                        glutSolidCube(dd);
                    glPopMatrix();
                }
                if((j==0 || j==2*n-1) && d<=a){
                    glPushMatrix();
                        glTranslatef(x,y,z);
                        glutSolidCube(dd);
                    glPopMatrix();
                }

            }
        }
    }
}
