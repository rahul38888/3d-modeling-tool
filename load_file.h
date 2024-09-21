//function reads a string and stores it in a string
#pragma once
inline void read_str(FILE *f, char *string)
{
    do {
    fgets(string, 255, f);
    } while ((string[0] == '/') || (string[0] == '\n'));
}

inline object * file_loader(const float * num, object *last, struct camera *cam, light *light, int type)
{
    if(type==1){
        last->type = static_cast<int>(num[0]);

        last->serial_no = static_cast<int>(num[1]);

        last->position[0]= static_cast<GLfloat>(num[2]);
        last->position[1]= static_cast<GLfloat>(num[3]);
        last->position[2]= static_cast<GLfloat>(num[4]);

        last->rotation[0]= static_cast<GLfloat>(num[5]);
        last->rotation[1]= static_cast<GLfloat>(num[6]);
        last->rotation[2]= static_cast<GLfloat>(num[7]);

        last->scale[0]= static_cast<GLfloat>(num[8]);
        last->scale[1]= static_cast<GLfloat>(num[9]);
        last->scale[2]= static_cast<GLfloat>(num[10]);

        if(last->type==1 || last->type==2){
            last->variables[0] = static_cast<GLfloat>(num[11]);
            last->variables[1] = static_cast<GLfloat>(num[12]);
            last->variables[2] = static_cast<GLfloat>(num[13]);

            last->mat = static_cast<materialType *>(malloc(sizeof(materialType)));

            materialType *mat = last->mat;
            mat->matEnable = static_cast<int>(num[14]);
            mat->smooth = static_cast<GLenum>(num[15]);

            mat->color[0]=static_cast<GLfloat>(num[16]);
            mat->color[1]=static_cast<GLfloat>(num[17]);
            mat->color[2]=static_cast<GLfloat>(num[18]);
            mat->color[3]=static_cast<GLfloat>(num[19]);

            mat->mat_ambient[0]=static_cast<GLfloat>(num[20]);
            mat->mat_ambient[1]=static_cast<GLfloat>(num[21]);
            mat->mat_ambient[2]=static_cast<GLfloat>(num[22]);

            mat->mat_diffuse[0]=static_cast<GLfloat>(num[23]);
            mat->mat_diffuse[1]=static_cast<GLfloat>(num[24]);
            mat->mat_diffuse[2]=static_cast<GLfloat>(num[25]);

            mat->mat_specular[0]=static_cast<GLfloat>(num[26]);
            mat->mat_specular[1]=static_cast<GLfloat>(num[27]);
            mat->mat_specular[2]=static_cast<GLfloat>(num[28]);

            mat->mat_shininess=static_cast<GLfloat>(num[29]);
        }
        else if(last->type==3 || last->type==4 || last->type==5 || last->type==6){
            last->variables[0]= static_cast<GLfloat>(num[11]);
            last->variables[1]= static_cast<GLfloat>(num[12]);
            last->variables[2]= static_cast<GLfloat>(num[13]);
            last->variables[3]= static_cast<GLfloat>(num[14]);

            last->mat = static_cast<materialType *>(malloc(sizeof(materialType)));

            materialType *mat = last->mat;
            mat->matEnable = static_cast<int>(num[15]);
            mat->smooth = static_cast<GLenum>(num[16]);

            mat->color[0]=static_cast<GLfloat>(num[17]);
            mat->color[1]=static_cast<GLfloat>(num[18]);
            mat->color[2]=static_cast<GLfloat>(num[19]);
            mat->color[3]=static_cast<GLfloat>(num[20]);

            mat->mat_ambient[0]=static_cast<GLfloat>(num[21]);
            mat->mat_ambient[1]=static_cast<GLfloat>(num[22]);
            mat->mat_ambient[2]=static_cast<GLfloat>(num[23]);

            mat->mat_diffuse[0]=static_cast<GLfloat>(num[24]);
            mat->mat_diffuse[1]=static_cast<GLfloat>(num[25]);
            mat->mat_diffuse[2]=static_cast<GLfloat>(num[26]);

            mat->mat_specular[0]=static_cast<GLfloat>(num[27]);
            mat->mat_specular[1]=static_cast<GLfloat>(num[28]);
            mat->mat_specular[2]=static_cast<GLfloat>(num[29]);

            mat->mat_shininess=static_cast<GLfloat>(num[30]);
        }
        else if(last->type==7){
            last->variables[0]= static_cast<GLfloat>(num[11]);

            last->mat = static_cast<materialType *>(malloc(sizeof(materialType)));

            materialType *mat = last->mat;
            mat->matEnable = static_cast<int>(num[12]);
            mat->smooth = static_cast<GLenum>(num[13]);

            mat->color[0]=static_cast<GLfloat>(num[14]);
            mat->color[1]=static_cast<GLfloat>(num[15]);
            mat->color[2]=static_cast<GLfloat>(num[16]);
            mat->color[3]=static_cast<GLfloat>(num[17]);

            mat->mat_ambient[0]=static_cast<GLfloat>(num[18]);
            mat->mat_ambient[1]=static_cast<GLfloat>(num[19]);
            mat->mat_ambient[2]=static_cast<GLfloat>(num[20]);

            mat->mat_diffuse[0]=static_cast<GLfloat>(num[21]);
            mat->mat_diffuse[1]=static_cast<GLfloat>(num[22]);
            mat->mat_diffuse[2]=static_cast<GLfloat>(num[23]);

            mat->mat_specular[0]=static_cast<GLfloat>(num[24]);
            mat->mat_specular[1]=static_cast<GLfloat>(num[25]);
            mat->mat_specular[2]=static_cast<GLfloat>(num[26]);

            mat->mat_shininess=static_cast<GLfloat>(num[27]);

        }
    }
    else if(type==2){

        cam->radius = static_cast<GLfloat>(num[0]);

        cam->sideAngle = static_cast<GLfloat>(num[1]);

        cam->upAngle = static_cast<GLfloat>(num[2]);

        cam->center[0] = static_cast<GLfloat>(num[3]);
        cam->center[1] = static_cast<GLfloat>(num[4]);
        cam->center[2] = static_cast<GLfloat>(num[5]);

        cam->up[0] = static_cast<GLfloat>(num[6]);
        cam->up[1] = static_cast<GLfloat>(num[7]);
        cam->up[2] = static_cast<GLfloat>(num[8]);
    }
    else if(type==3){

        light->on = static_cast<int>(num[0]);

        light->number = static_cast<int>(num[1]);

        light->light_ambient[0] = static_cast<GLfloat>(num[2]);
        light->light_ambient[1] = static_cast<GLfloat>(num[3]);
        light->light_ambient[2] = static_cast<GLfloat>(num[4]);

        light->light_diffuse[0] = static_cast<GLfloat>(num[5]);
        light->light_diffuse[1] = static_cast<GLfloat>(num[6]);
        light->light_diffuse[2] = static_cast<GLfloat>(num[7]);

        light->light_specular[0] = static_cast<GLfloat>(num[8]);
        light->light_specular[1] = static_cast<GLfloat>(num[9]);
        light->light_specular[2] = static_cast<GLfloat>(num[10]);

        light->light_position[0] = static_cast<GLfloat>(num[11]);
        light->light_position[1] = static_cast<GLfloat>(num[12]);
        light->light_position[2] = static_cast<GLfloat>(num[13]);

        light->light_attenuation[0] = static_cast<GLfloat>(num[14]);
        light->light_attenuation[1] = static_cast<GLfloat>(num[15]);

    }

    return nullptr;
}
