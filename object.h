#pragma once
inline void drawSolidCuboid(struct object *obj){
    const GLfloat l=obj->variables[0]/2;
    const GLfloat b=obj->variables[1]/2;
    const GLfloat h=obj->variables[2]/2;

    glNormal3f(1,0,0);
            glBegin(GL_POLYGON);
                glTexCoord2f(0,0);
                glVertex3f(l,h,b);
                glTexCoord2f(1,0);
                glVertex3f(l,-h,b);
                glTexCoord2f(1,1);
                glVertex3f(-l,-h,b);
                glTexCoord2f(0,1);
                glVertex3f(-l,h,b);
            glEnd();

            glNormal3f(-1,0,0);
            glBegin(GL_POLYGON);
                glTexCoord2f(0,0);
                glVertex3f(l,h,-b);
                glTexCoord2f(0,1);
                glVertex3f(l,-h,-b);
                glTexCoord2f(1,1);
                glVertex3f(-l,-h,-b);
                glTexCoord2f(1,0);
                glVertex3f(-l,h,-b);
            glEnd();

            glNormal3f(0,0,1);
            glBindTexture(GL_TEXTURE_2D, obj->mat->texture);
            glBegin(GL_POLYGON);
                glTexCoord2f(0,0);
                glVertex3f(l,h,b);
                glTexCoord2f(0,1);
                glVertex3f(l,h,-b);
                glTexCoord2f(1,1);
                glVertex3f(l,-h,-b);
                glTexCoord2f(1,0);
                glVertex3f(l,-h,b);
            glEnd();

            glNormal3f(0,0,-1);
            glBegin(GL_POLYGON);
                glTexCoord2f(0,0);
                glVertex3f(-l,h,b);
                glTexCoord2f(0,1);
                glVertex3f(-l,h,-b);
                glTexCoord2f(1,1);
                glVertex3f(-l,-h,-b);
                glTexCoord2f(1,0);
                glVertex3f(-l,-h,b);
            glEnd();

            glNormal3f(0,1,0);
            glBegin(GL_POLYGON);
                glTexCoord2f(0,0);
                glVertex3f(l,h,b);
                glTexCoord2f(0,1);
                glVertex3f(-l,h,b);
                glTexCoord2f(1,1);
                glVertex3f(-l,h,-b);
                glTexCoord2f(1,0);
                glVertex3f(l,h,-b);
            glEnd();

            glNormal3f(0,-1,0);
            glBegin(GL_POLYGON);
                glTexCoord2f(0,0);
                glVertex3f(l,-h,b);
                glTexCoord2f(0,1);
                glVertex3f(-l,-h,b);
                glTexCoord2f(1,1);
                glVertex3f(-l,-h,-b);
                glTexCoord2f(1,0);
                glVertex3f(l,-h,-b);
            glEnd();

}

inline void drawSolidSphere(struct object * obj){
    const float r = obj->variables[0];

    for(int i = 0; i <= obj->variables[1]; i++) {
        const double lat0 = M_PI * (-0.5 + (double) (i - 1) / obj->variables[1]);
        const double z0 = r * sin(lat0);
        const double zr0 = cos(lat0);

        const double lat1 = M_PI * (-0.5 + (double) i / obj->variables[1]);
        const double z1 = r * sin(lat1);
        const double zr1 = cos(lat1);

        glBegin(GL_QUAD_STRIP);
        for(int j = 0; j <= obj->variables[2]; j++) {
            const double lng = 2 * M_PI * (double) (j - 1) / obj->variables[2];
            const double x = r * cos(lng);
            const double y = r * sin(lng);

            glNormal3f(x * zr0, y * zr0, z0);
            glVertex3f(x * zr0, y * zr0, z0);
            glNormal3f(x * zr1, y * zr1, z1);
            glVertex3f(x * zr1, y * zr1, z1);
        }
        glEnd();
    }
}

inline void drawSolidCone(struct object * obj){
    int i, j;

    const float h = obj->variables[1];
    const float r = obj->variables[0];

    double prad;

    const double latg = static_cast<double>(r) / static_cast<double>(h);
    const double latgsin=1/sqrt(1+latg*latg);
    const double latgcos=1/sqrt(1+latg*latg);
    const double hgap=static_cast<double>(h)/static_cast<double>(obj->variables[2]);
    const double latgap=2*M_PI/static_cast<double>(obj->variables[3]);

    double lat0=(-latgap);
    double lat1=0;

    for(i=0;i<=obj->variables[3];i++){
        double prht=h;
        lat0+=latgap;
        lat1+=latgap;
        const double lat0sin=sin(lat0);
        const double lat0cos=cos(lat0);
        const double  lat1sin=sin(lat1);
        const double  lat1cos=cos(lat1);
        glBegin(GL_QUAD_STRIP);
            for(j=0,prad=0.2;j<=obj->variables[2];j++){
                prad=static_cast<double>(j)*latg*hgap;

                glNormal3f(lat0cos*latgsin,latgcos,lat0sin*latgsin);
                glVertex3f(prad*lat0cos,prht,prad*lat0sin);
                glNormal3f(lat1cos*latgsin,latgcos,lat1sin*latgsin);
                glVertex3f(prad*lat1cos,prht,prad*lat1sin);

                prht-=hgap;
            }
        glEnd();
    }

    lat0=(-latgap);
    lat1=0;

    glNormal3f(0,-1,0);
    for(i=0;i<=obj->variables[3];i++){
        lat0+=latgap;
        lat1+=latgap;
        glBegin(GL_TRIANGLES);
            glVertex3f(0,0,0);
            glVertex3f(r*cos(lat0),0,r*sin(lat0));
            glVertex3f(r*cos(lat1),0,r*sin(lat1));
        glEnd();
    }

}

inline void drawSolidTorus(struct object *obj){
    const GLfloat r=obj->variables[1];
    const GLfloat th=obj->variables[0];
    const int numc=obj->variables[2], numt=obj->variables[3];

    const double twopi = 2 * (double) M_PI;
   for (int i = 0; i < numc; i++) {
      glBegin(GL_QUAD_STRIP);
      for (int j = 0; j <= numt; j++) {
         for (int k = 1; k >= 0; k--) {
            double s = (i + k) % numc + 0.5;
            double t = j % numt;

            double x = (r + th * cos(s * twopi / numc)) * cos(t * twopi / numt);
            double y = (r + th * cos(s * twopi / numc)) * sin(t * twopi / numt);
            double z = th * sin(s * twopi / numc);
            glNormal3f(cos(s*twopi/numc)*cos(t*twopi/numt),cos(s*twopi/numc)*sin(t*twopi/numt),sin(s*twopi/numc));
            glVertex3f(x, y, z);
         }
      }
      glEnd();
   }
}

inline void drawSolidCylinder(struct object *obj){
    int i, j;
    const auto r=static_cast<double>(obj->variables[0]);
    const auto h=static_cast<double>(obj->variables[1]);

    const double hgap=h/obj->variables[3];
    const double latgap=2*M_PI/obj->variables[2];
    double lat0=-latgap;
    double lat1=0;

    for(i=0;i<=obj->variables[2];i++){
        double prht = h;
        lat0+=latgap;
        lat1+=latgap;
        const double lat0sin = sin(lat0);double lat0cos = cos(lat0);
        const double lat1sin = sin(lat1);double lat1cos = cos(lat1);
        glBegin(GL_QUAD_STRIP);
            for(j=0;j<=obj->variables[3];j++){

                glNormal3f(lat0cos,0,lat0sin);
                glVertex3f(r*lat0cos,prht,r*lat0sin);
                glNormal3f(lat1cos,0,lat1sin);
                glVertex3f(r*lat1cos,prht,r*lat1sin);

                prht-=hgap;
            }
        glEnd();
    }

    glNormal3f(0,-1,0);
    for(i=0;i<=obj->variables[3];i++){
        lat0+=latgap;
        lat1+=latgap;
        glBegin(GL_TRIANGLES);
            glVertex3f(0,0,0);
            glVertex3f(r*cos(lat0),0,r*sin(lat0));
            glVertex3f(r*cos(lat1),0,r*sin(lat1));
        glEnd();
    }

    glNormal3f(0,1,0);
    for(i=0;i<=obj->variables[3];i++){
        lat0+=latgap;
        lat1+=latgap;
        glBegin(GL_TRIANGLES);
            glVertex3f(0,h,0);
            glVertex3f(r*cos(lat0),h,r*sin(lat0));
            glVertex3f(r*cos(lat1),h,r*sin(lat1));
        glEnd();
    }
}

inline void drawSolidPlane(object *obj){
    const GLfloat xgap = obj->variables[0] / obj->variables[2];
    const GLfloat zgap = obj->variables[1] / obj->variables[3];


    for(GLfloat x0 = obj->variables[0] / 2;x0>-obj->variables[0]/2;x0-=xgap){
        glBegin(GL_QUAD_STRIP);
            for(GLfloat z0 = obj->variables[1] / 2;z0>=-obj->variables[1]/2;z0-=zgap){
                glNormal3f(0.0f, 1.0f, 0.0f);
                glVertex3f(x0,0,z0);
                glNormal3f(0.0f, 1.0f, 0.0f);
                glVertex3f(x0-xgap,0,z0);
            }
        glEnd();
    }

}

inline void drawWireCuboid(struct object *obj){
    const GLfloat l=obj->variables[0]/2;
    GLfloat b=obj->variables[1]/2, h=obj->variables[2]/2;

            glBegin(GL_LINE_STRIP);
                glVertex3f(l,h,b);
                glVertex3f(-l,h,b);
                glVertex3f(-l,h,-b);
                glVertex3f(l,h,-b);
                glVertex3f(l,h,b);
            glEnd();

            glBegin(GL_LINE_STRIP);
                glVertex3f(l,-h,b);
                glVertex3f(-l,-h,b);
                glVertex3f(-l,-h,-b);
                glVertex3f(l,-h,-b);
                glVertex3f(l,-h,b);
            glEnd();

            glBegin(GL_LINES);
                glVertex3f(l,h,b);
                glVertex3f(l,-h,b);
            glEnd();

            glBegin(GL_LINES);
                glVertex3f(-l,h,b);
                glVertex3f(-l,-h,b);
            glEnd();

            glBegin(GL_LINES);
                glVertex3f(-l,h,-b);
                glVertex3f(-l,-h,-b);
            glEnd();
            glBegin(GL_LINES);
                glVertex3f(l,h,-b);
                glVertex3f(l,-h,-b);
            glEnd();

}

inline void drawWireSphere(struct object * obj){
    int i;
    const float r = obj->variables[0];
    double agap = M_PI / obj->variables[1];
    double pang = 0;

    for(i=1; i<obj->variables[2];i++){
        pang+=agap;
        const double prht = r * cos(pang);
        const double prrd = r * sin(pang);
        glPushMatrix();
            glTranslatef(0,0,prht);
            glRotatef(90,1,0,0);
            draw_circle(prrd,obj->variables[1]);
        glPopMatrix();
    }

    agap=360/obj->variables[1];
    pang=0;
    for(i=0;i<obj->variables[1]/2;i++){
        glPushMatrix();
            glRotatef(90,0,1,0);
            glRotatef(pang,1,0,0);
            draw_circle(r+0.01,obj->variables[2]);
        glPopMatrix();
        pang+=agap;
    }
}

inline void drawWireCone(struct object * obj){
    int i, j;
    double prad;

    const float h = obj->variables[1];
    const float r = obj->variables[0];

    const double latg = static_cast<double>(r) / static_cast<double>(h);
    const double hgap = static_cast<double>(h) / static_cast<double>(obj->variables[2]);

    double prht = h;
    for(j=0,prad=0.2;j<=obj->variables[2];j++){
        prad=static_cast<double>(j)*latg*hgap;
        glPushMatrix();
            glTranslatef(0,prht,0);
            draw_circle(prad,obj->variables[3]);
        glPopMatrix();
        prht-=hgap;
    }


    double lat0 = 0;
    const double latgap = 2 * M_PI / static_cast<double>(obj->variables[3]);
    for(i=0;i<=obj->variables[3];i++){
        glBegin(GL_LINES);
            glVertex3f(0,h,0);
            glVertex3f(r*cos(lat0),0,r*sin(lat0));
        glEnd();
        lat0+=latgap;
    }

    lat0=(-latgap);
    double lat1 = 0;

    glNormal3f(0,-1,0);
    for(i=0;i<=obj->variables[3];i++){
        lat0+=latgap;
        lat1+=latgap;
        glBegin(GL_LINE_STRIP);
            glVertex3f(0,0,0);
            glVertex3f(r*cos(lat0),0,r*sin(lat0));
            glVertex3f(r*cos(lat1),0,r*sin(lat1));
        glEnd();
    }

}

inline void drawWireCylinder(struct object *obj){
    const auto r=static_cast<double>(obj->variables[0]);
    const auto h=static_cast<double>(obj->variables[1]);

    double lat1;

    double hgap = h / obj->variables[3];
    const double latgap = 2 * M_PI / obj->variables[2];
    double lat0 = -latgap;

    for(int i = 0;i<=obj->variables[2];i++){
        lat0+=latgap;
        glBegin(GL_LINES);
            glVertex3f(r*cos(lat0),0,r*sin(lat0));
            glVertex3f(r*cos(lat0),h,r*sin(lat0));
        glEnd();
    }

    double prht = h;
    /*for(j=0;j<=obj->variables[3];j++){
        glPushMatrix();
            glTranslated(0,prht,0);
            draw_circle(r,obj->variables[2]);
        glPopMatrix();
        prht-=hgap;
    }*/

}

inline void drawWirePlane(struct object *obj){
    const GLfloat a = obj->variables[0] / 2;
    const GLfloat b = obj->variables[1] / 2;

    const GLfloat xgap = obj->variables[0] / obj->variables[2];
    const GLfloat zgap = obj->variables[1] / obj->variables[3];

    for(GLfloat x0 = a;x0>=-a;x0-=xgap){
        glBegin(GL_LINES);
            glVertex3f(x0,0,b);
            glVertex3f(x0,0,-b);
        glEnd();
    }

    for(GLfloat z0 = b;z0>=-b;z0-=zgap){
        glBegin(GL_LINES);
            glVertex3f(a,0,z0);
            glVertex3f(-a,0,z0);
        glEnd();
    }

}







