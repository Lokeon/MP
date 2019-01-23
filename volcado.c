#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "volcado.h"

static faltas* inicializa_fal(faltas*);
static faltas* cargar_faltas(faltas*, int*);

static calificaciones* inicializa_cal(calificaciones*);
static calificaciones* cargar_calificaciones(calificaciones*, int *);

static matriculas* inicializa_matri(matriculas *);
static matriculas* cargar_matriculas(matriculas *, int *);

static materias* inicializa_mat(materias *);
static materias* cargar_materias(materias *, int *);

static horarios* inicializa_hor(horarios*);
static horarios* cargar_horarios(horarios*, int *);

static alumnos* inicializa_al(alumnos *);
static alumnos* cargar_alumnos(alumnos *, int *);

static usuarios *inicializa_us(usuarios *);
static usuarios *cargar_usuarios(usuarios *, int *);

void volcar(usuarios **us, alumnos **al, horarios **hor, materias **mat, matriculas **matri, int *n1, int *n2, int *n3, int *n4, int *n5){
    *us = cargar_usuarios(*us,&(*n1));
    *al = cargar_alumnos(*al,&(*n2));
    *hor = cargar_horarios(*hor,&(*n3));
    *mat = cargar_materias(*mat,&(*n4));
    *matri = cargar_matriculas(*matri,&(*n5));
}

static usuarios* inicializa_us(usuarios *us){

    if((us = (usuarios*)malloc(sizeof(usuarios)))==NULL){
        printf("Error.");
        exit(5);
    }

    return us;
}

static usuarios* cargar_usuarios(usuarios  *us, int *i){
    FILE *f;
    char c;

    if((f = fopen("usuarios.txt","r"))==NULL){
        printf("ERROR no se ha podido abrir el fichero.");
        exit(1);
    }

    us = inicializa_us(us);

    do{
       fscanf(f,"%[^-]",us[*i].id_usuario);
       us[*i].id_usuario[3] = '\0';
       c = fgetc(f);

       fscanf(f,"%[^-]",us[*i].nomb_usuario);
       us[*i].nomb_usuario[strlen(us[*i].nomb_usuario)] = '\0';
       c = fgetc(f);

       fscanf(f,"%[^-]",us[*i].perfil_usuario);
       us[*i].perfil_usuario[strlen(us[*i].perfil_usuario)] = '\0';
       c = fgetc(f);

       fscanf(f,"%[^-]",us[*i].usuario);
       us[*i].usuario[5] = '\0';
       c = fgetc(f);

       fscanf(f,"%[^\n]",us[*i].contrasena);
       us[*i].contrasena[8] = '\0';
       c = fgetc(f);

       if(!feof(f)){
           (*i)++;

           us = (usuarios*) realloc(us,(((*i)+1)*sizeof(usuarios)));
           if(us == NULL){
                printf("ERROR.");
                exit(5);
           }
       }
    }while(!feof(f));

    fclose(f);

    return us;
}

static alumnos* inicializa_al(alumnos *al){
    if((al = (alumnos*)malloc(sizeof(alumnos)))==NULL){
        printf("ERROR.\n");
        exit(1);
    }
    return al;
}

static alumnos* cargar_alumnos(alumnos *al, int *i){
    char c;
    FILE *f;

    if((f = fopen("alumnos.txt","r")) == NULL){
        printf("ERROR.");
        exit(1);
    }

    al = inicializa_al(al);

    do{
        fscanf(f,"%[^-]",al[*i].id_alum);
        al[*i].id_alum[6] = '\0';
        c = fgetc(f);

        fscanf(f,"%[^-]",al[*i].nombre_alum);
        al[*i].nombre_alum[strlen(al[*i].nombre_alum)] = '\0';
        c = fgetc(f);

        fscanf(f,"%[^-]",al[*i].direc_alum);
        al[*i].direc_alum[strlen(al[*i].direc_alum)] = '\0';
        c = fgetc(f);

        fscanf(f,"%[^-]",al[*i].local_alum);
        al[*i].local_alum[strlen(al[*i].local_alum)] = '\0';
        c = fgetc(f);

        fscanf(f,"%[^-]",al[*i].curso);
        al[*i].curso[strlen(al[*i].curso)] = '\0';
        c = fgetc(f);

        fscanf(f,"%[^\n]",al[*i].grupo);
        al[*i].grupo[strlen(al[*i].grupo)] = '\0';
        c = fgetc(f);

        if(!feof(f)){
           (*i)++;

            al = (alumnos*)realloc(al,(((*i)+1)*sizeof(alumnos)));
            if(al == NULL){
                printf("ERROR.");
                exit(5);
            }
        }
    }while(!feof(f));

    fclose(f);

    return al;
}

static horarios* inicializa_hor(horarios* hor){
    if((hor = (horarios*)malloc(sizeof(horarios)))==NULL){
        printf("ERROR.\n");
        exit(1);
    }

    return hor;
}

static horarios* cargar_horarios(horarios* hor, int *i){
    FILE *f;
    char c;

    if((f = fopen("horarios.txt","r")) == NULL){
        printf("ERROR.");
        exit(1);
    }

    hor = inicializa_hor(hor);

    do{
        fscanf(f,"%[^-]",hor[*i].id_profesor);
        hor[*i].id_profesor[4] = '\0';
        c = fgetc(f);

        fscanf(f,"%d",&hor[*i].dia_clase);
        c = fgetc(f);

        fscanf(f,"%d",&hor[*i].hora_clase);
        c = fgetc(f);

        fscanf(f,"%[^-]",hor[*i].id_materia);
        hor[*i].id_materia[4] = '\0';
        c = fgetc(f);

        fscanf(f,"%[^\n]",hor[*i].grupo);
        hor[*i].grupo[strlen(hor[*i].grupo)] = '\0';
        c = fgetc(f);

        if(!feof(f)){
           (*i)++;

            hor = (horarios*)realloc(hor,(((*i)+1)*sizeof(horarios)));
            if(hor == NULL){
                printf("ERROR.");
                exit(5);
            }
        }

    }while(!feof(f));

    fclose(f);

    return hor;
}

static materias* inicializa_mat(materias *mat){
    if((mat = (materias*)malloc(sizeof(materias)))==NULL){
        printf("ERROR.\n");
        exit(1);
    }

    return mat;
}

static materias* cargar_materias(materias *mat,  int *i){
    char c;
    FILE *f;

    if((f = fopen("materias.txt","r")) == NULL){
        printf("ERROR.");
        exit(1);
    }

    mat = inicializa_mat(mat);

    do{
        fscanf(f,"%[^-]",mat[*i].id_materia);
        mat[*i].id_materia[4] = '\0';
        c = fgetc(f);

        fscanf(f,"%[^-]",mat[*i].nombre_materia);
        mat[*i].nombre_materia[strlen(mat[*i].nombre_materia)] = '\0';
        c = fgetc(f);

        fscanf(f,"%[^\n]",mat[*i].abrev_materia);
        mat[*i].abrev_materia[3] = '\0';
        c = fgetc(f);

        if(!feof(f)){
           (*i)++;

            mat = (materias*)realloc(mat,(((*i)+1)*sizeof(materias)));
            if(mat == NULL){
                printf("ERROR.");
                exit(5);
            }
        }
    }while(!feof(f));

    fclose(f);

    return mat;
}

static matriculas* inicializa_matri(matriculas *matri){
    if((matri = (matriculas*)malloc(sizeof(matriculas)))==NULL){
        printf("ERROR.\n");
        exit(1);
    }

    return matri;
}

static matriculas* cargar_matriculas(matriculas *matri, int *i){
    char c;
    FILE *f;

    matri = inicializa_matri(matri);

    if((f = fopen("matriculas.txt","r"))==NULL){
        printf("ERROR.\n");
        exit(1);
    }

    do{
        fscanf(f,"%[^-]", matri[*i].id_materia);
        matri[*i].id_materia[4] = '\0';
        c = fgetc(f);

        fscanf(f, "%[^\n]", matri[*i].id_alum);
        matri[*i].id_alum[6] = '\0';
        c = fgetc(f);

        if(!feof(f)){
           (*i)++;

            matri = (matriculas*)realloc(matri,(((*i)+1)*sizeof(matriculas)));
            if(matri == NULL){
                printf("ERROR.");
                exit(5);
            }
        }


    }while(!feof(f));

    fclose(f);

    return matri;
}

static calificaciones *inicializa_al(calificaciones *cal){
    if((cal = (calificaciones*)malloc(sizeof(calificaciones)))==NULL){
        printf("ERROR.\n");
        exit(1);
    }

    return cal;
}

static calificaciones *cargar_calificaciones(calificaciones *cal, int *i){
    char c;
    FILE *f;

    cal = inicializa_cal(cal);

    if((f = fopen("calificaciones.txt","r"))==NULL){
        printf("ERROR.\n");
        exit(1);
    }

    do{
        fscanf(f,"%d/%d/%d",cal[*i].fecha_calif.dia,cal[*i].fecha_calif.mes,cal[*i].fecha_calif.ano);
        c = fgetc(f);

        fscanf(f, "%[^-]", cal[*i].descrip_calif);
        cal[*i].descrip_calif[strlen(cal[*i].descrip_calif)] = '\0';
        c = fgetc(f);

        fscanf(f,"%[^-]", cal[*i].id_materia);
        cal[*i].id_materia[4] = '\0';
        c = fgetc(f);

        fscanf(f, "%[^-]", cal[*i].id_alum);
        cal[*i].id_alum[6] = '\0';
        c = fgetc(f);

        fscanf(f,"%d",cal[*i].valor_calif);
        c = fgetc(f);

        if(!feof(f)){
           (*i)++;

            cal = (calificaciones*)realloc(cal,(((*i)+1)*sizeof(calificaciones)));
            if(cal == NULL){
                printf("ERROR.");
                exit(5);
            }
        }


    }while(!feof(f));

    fclose(f);

    return cal;
}

faltas* inicializa_fal(faltas *fal){
    if((fal = (faltas*)malloc(sizeof(faltas)))==NULL){
        printf("ERROR.\n");
        exit(1);
    }
    return fal;
}

fatas* cargar_faltas(faltas* fal, int *i){
    char c;
    FILE *f;

    fal = inicializa_cal(fal);

    if((f = fopen("faltas.txt","r"))==NULL){
        printf("ERROR.\n");
        exit(1);
    }

    do{
        fscanf(f,"%d/%d/%d",fal[*i].fecha_falta.dia,fal[*i].fecha_falta.mes,fal[*i].fecha_falta.ano);
        c = fgetc(f);

        fscanf(f, "%d", fal[*i].hora_falta);
        c = fgetc(f);

        fscanf(f,"%[^-]", fal[*i].descrip_falta);
        fal[*i].descrip_falta[strlen(fal[*i].descrip_falta)] = '\0';
        c = fgetc(f);

        fscanf(f, "%[^-]", fal[*i].estado_falta);
        fal[*i].descrip_falta[strlen(fal[*i].descrip_falta)] = '\0';
        c = fgetc(f);

        fscanf(f, "%[^\n]", fal[*i].id_alum);
        fal[*i].id_alum[6] = '\0';
        c = fgetc(f);

        if(!feof(f)){
           (*i)++;

            fal = (faltas*)realloc(fal,(((*i)+1)*sizeof(faltas)));
            if(fal == NULL){
                printf("ERROR.");
                exit(5);
            }
        }


    }while(!feof(f));

    fclose(f);

    return fal;
}

