#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "volcado.h"
#include "profesor.h"


void sobreescribir_alumnos(alumnos *, int );
void sobreescribir_calificaciones(calificaciones*, int );
alumnos *ficha(alumnos *, int* , int);
calificaciones *calificaciones_change(calificaciones *, int*, char *);
faltas *faltas_change(faltas*, int*, char* );

void menu_profesor(alumnos *al, horarios *hor, materias *mat, matriculas *matri, calificaciones *cal, faltas *fal, int *n2, int *n3, int *n4, int *n5, int *n6, int *n7 char *id_prof){
    int i, j, k, i1, op, op2, op3, op4;
    char otra_vez;

    do{
        system("cls");
        for(i=0; i<=*n3; i++){
            if(strcmp(hor[i].id_profesor, id_prof) == 0){
                for(j=0; j<=*n4; j++){
                    if(strcmp(hor[i].id_materia, mat[j].id_materia) == 0){
                        printf("%d.-GRUPO %s MATERIA %s\n", j, hor[i].grupo, mat[j].nombre_materia);
                    }
                }
            }
        }

        printf("Elige un grupo: ");
        scanf("%d", &op);

        do{
            printf("1.-Lista de alumnos.\n");
            printf("2.-Cambiar de grupo.\n");
            scanf("%d", &op2);
        }while(op2 < 1 || op2 > 2);

    }while(op2 == 2);

    do{
        for(k=0; k<=*n5; k++){
            if(strcmp(mat[op].id_materia,matri[k].id_materia) == 0){
                for(i1=0; i1<*n2; i1++){
                    if(strcmp(matri[k].id_alum,al[i1].id_alum) ==0 ){
                        printf("%d.-%s\n",i1,al[i1].nombre_alum);
                    }
                }
            }
        }

        printf("Elige un alumno: ");
        scanf("%d",&op3);

        do{
            printf("ALUMNO: %s\n", al[op3].nombre_alum);
            printf("1.-Ficha del alumno.\n2.-Calificaciones del alumno.\n3.-Faltas de asistencia.\n4.-Volver\n");
            scanf("%d",&op4);
        }while(op<1 || op>4);

    }while(op4 == 4);

    do{
        if(otra_vez == 's'){
            printf("Introduce otra opcion:");
            scanf("%d",&op4);
        }

        switch(op4){
            case 1:
                ficha(al,&n2,op3);
                break;
            case 2:
                calificaciones_change(cal,&n6,al[op3].id_alum);
                break;
            case 3:
                faltas(fal,&n7,al[op3].id_alum);
                break;
        }

        printf("¿Quieres realizar mas cambios? (s/n) ");
        scanf("%c",otra_vez);
    }while(otra_vez == 's');

}

alumnos* ficha(alumnos *al, int *n2, int op3){
    int op;
    char cadena[100];
    char c;

    do{
        printf("%s-%s-%s-%s-%s-%s\n",al[op3].id_alum,al[op3].nombre_alum,al[op3].direc_alum,al[op3].local_alum,al[op3].curso,al[op3].grupo);
        do{
            printf("¿Que dato quieres modificar?\n");
            printf("1.-Identificador.\n2.-Nombre.\n3.-Direcciones.\n4.-Localidad.\n5.-Curso.\n6.-Grupo.\n");
            scanf("%d",&op);
        }while(op < 1 || op > 6);

        switch(op){
            case 1:
                printf("Introduce el nuevo dato: ");
                fflush(stdin);
                gets(cadena);
                strcpy(al[op3].id_alum,cadena);
                break;
            case 2:
                printf("Introduce el nuevo dato: ");
                fflush(stdin);
                gets(cadena);
                strcpy(al[op3].nombre_alum,cadena);
                break;
            case 3:
                printf("Introduce el nuevo dato: ");
                fflush(stdin);
                gets(cadena);
                strcpy(al[op3].direc_alum,cadena);
                break;
            case 4:
                printf("Introduce el nuevo dato: ");
                fflush(stdin);
                gets(cadena);
                strcpy(al[op3].local_alum,cadena);
                break;
            case 5:
                printf("Introduce el nuevo dato: ");
                fflush(stdin);
                gets(cadena);
                strcpy(al[op3].curso,cadena);
                break;
            case 6:
                printf("Introduce el nuevo dato: ");
                fflush(stdin);
                gets(cadena);
                strcpy(al[op3].grupo,cadena);
                break;
        }

        printf("¿Desea realizar mas cambios en la ficha de un alumno? (s/n) ");
        scanf("%c",&c);
    }while(c == 's');

    sobreescibir_alumnos(al, *n2);

    return al;
}

void sobreescribir_alumnos(alumnos *al, int n2){
    int i;
    FILE *f;

    if((f = fopen("alumnos.txt","w"))==NULL){
        printf("ERROR.\n");
        exit(1);
    }

    for(i=0; i<=n2; i++){
        if(i != n2){
            fprintf(f,"%s-%s-%s-%s-%s-%s\n",al[i].id_alum,al[i].nombre_alum,al[i].direc_alum,al[i].local_alum,al[i].curso,al[i].grupo);
        }
        else{
            fprintf(f,"%s-%s-%s-%s-%s-%s",al[i].id_alum,al[i].nombre_alum,al[i].direc_alum,al[i].local_alum,al[i].curso,al[i].grupo);
        }
    }

    fclose(f);
}


calificaciones *calificaciones_change(calificaciones *cal, int *n, char *id_alum){
    int i, op, op2;

    for(i=0; i<=*n; i++){
        if(strcmp(cal[i].id_alum,id_alum)==0){
            printf("%d.-%d/%d/%d-%s-%s-%s-%d\n", i, cal[i].fecha_calif.dia,cal[i].fecha_calif.mes,cal[i].fecha_calif.ano,cal[i].descrip_calif,cal[i].id_materia,cal[i].id_alum,cal[i].valor_calif);
        }
    }
    printf("1.-Cambiar una calificacion del alumno.\n");
    printf("2.-Anadir una calificacion.\n");
    printf("3.-Borrar una nueva calificacon.\n");
    scanf("%d", &op);

    switch(op){
        case 1:
            for(i=0; i<=*n; i++){
                if(strcmp(cal[i].id_alum,id_alum)==0){
                    printf("%d.-%d/%d/%d-%s-%s-%s-%d\n", i, cal[i].fecha_calif.dia,cal[i].fecha_calif.mes,cal[i].fecha_calif.ano,cal[i].descrip_calif,cal[i].id_materia,cal[i].id_alum,cal[i].valor_calif);
                }
            }
            printf("Introduce una calificacion a cambiar: ");
            scanf("%d",&op2);

            printf("dia/mes/ano: ");
            scanf("%d/%d/%d",&cal[op2].fecha_calif.dia,&cal[op2].fecha_calif.mes,cal[op2].fecha_calif.ano);

            printf("Descripcion: ");
            fflush(stdin);
            gets(cal[op2].descrip_calif);

            printf("Nota: ");
            scanf("%d", &cal[op2].valor_calif);
            break;

        case 2:
            (*n)++;
            cal = (calificaciones*)realloc(cal,((*n)+1)*sizeof(calificaciones);
            if(cal == NULL){
                printf("ERROR.\n");
                exit(1);
            }

            printf("dia/mes/ano: ");
            scanf("%d/%d/%d",&cal[(*n)-1].fecha_calif.dia,&cal[(*n)-1].fecha_calif.mes,&cal[(*n)-1].fecha_calif.ano);

            printf("Descripcion de la calificacion: ");
            gets(cal[(*n)-1].descrip_calif);

            printf("Identificador de la materia: ");
            gets(cal[(*n)-1].id_materia);

            printf("Identificador del alumno: ");
            gets(cal[(*n)-1].id_alum);

            printf("Nota: ");;
            scanf("%d",&cal[(*n)-1].valor_calif);

            break;

        case 3:
            for(i=0; i<=*n; i++){
                if(strcmp(cal[i].id_alum,id_alum)==0){
                    printf("%d.-%d/%d/%d-%s-%s-%s-%d\n", i, cal[i].fecha_calif.dia,cal[i].fecha_calif.mes,cal[i].fecha_calif.ano,cal[i].descrip_calif,cal[i].id_materia,cal[i].id_alum,cal[i].valor_calif);
                }
            }
            printf("Introduce una calificacion a borrar: ");
            scanf("%d",&op2);

            for(i=op2; i<=*n; i++){
                cal[i].fecha_calif.dia = cal[i+1].fecha_calif.dia;
                cal[i].fecha_calif.mes = cal[i+1].fecha_calif.mes;
                cal[i].fecha_calif.ano = cal[i+1].fecha_calif.ano;

                strcpy(cal[i].descrip_calif,cal[i+1].descrip_calif);
                strcpy(cal[i].id_materia,cal[i+1].id_materia);
                strcpy(cal[i].id_alum,cal[i+1].id_alum);
                cal[i].valor_calif = cal[i+1].valor_calif;
            }

            (*n)--;

            cal = (calificaciones*)realloc(cal,(*n)*sizeof(calificaciones));
            if(cal == NULL){
                printf("ERROR.\n");
                exit(1);
            }

            break;
    }

    sobreescibir_calificaciones(cal);

    return cal;
}

void sobreescribir_calificaciones(calificaciones *cal, int n){
    int i;
    FILE *f;

    if((f = fopen("calificaciones.txt","w"))==NULL){
        printf("ERROR.\n");
        exit(1);
    }

    for(i=0; i<=n; i++){
        if(i != n){
            fprintf(f,"%d/%d/%d-%s-%s-%s-%d\n",cal[i].fecha_calif.dia,cal[i].fecha_calif.mes,cal[i].fecha_calif.ano,cal[i].descrip_calif,cal[i].id_materia,cal[i].id_alum,cal[i].valor_calif);
        }
        else{
            fprintf(f,"%d/%d/%d-%s-%s-%s-%d",cal[i].fecha_calif.dia,cal[i].fecha_calif.mes,cal[i].fecha_calif.ano,cal[i].descrip_calif,cal[i].id_materia,cal[i].id_alum,cal[i].valor_calif);
        }
    }

    fclose(f);
}

faltas* faltas_change(faltas *fal, int *n, char id_alum ){
    int i, op;

    printf("1.-Modificar una falta de la lista.\n");
    printf("2.-Anadir una nueva falta.\n");
    printf("3.-Borrar una falta.\n");
    printf("Introduzca una opcion: ");
    scanf("%d", &op);

    switch(op){
        case 1:

            for(i=0; i<=n; i++){
                if(strcmp(fal[i].id_alum,id_alum)==0){
                    printf("%d.-%d/%d/%d-%d-%s-%s-%s\n",i, fal[i].fecha_falta.dia,fal[i].fecha_falta.mes,fal[i].fecha_falta.ano,fal[i].hora_falta,fal[i].descrip_falta,fal[i].estado_falta,fal[i].id_alum);
                }
            }
            printf("Elige una para cambiarla: ");
            scanf("%d", &op2);

            printf("dia/mes/ano: ");
            scanf("%d/%d/%d",&fal[op2].fecha_falta.dia,&fal[op2].fecha_falta.mes,&fal[op2].fecha_falta.ano);

            printf("Hora de la falta: ");
            scanf("%d",&fal[op2].hora_falta);

            printf("Descripcion de la falta: ");
            gets(fal[op2].descrip_falta);

            printf("Estado de la falta: ");
            gets(fal[op2].estado_falta);

            break;

        case 2:
            (*n)++;
            fal = (faltas*)realloc(fal,((*n)+1)*sizeof(faltas);
            if(fal == NULL){
                printf("ERROR.\n");
                exit(1);
            }

            printf("dia/mes/ano: ");
            scanf("%d/%d/%d",&fal[(*n)-1].fecha_falta.dia,&fal[(*n)-1].fecha_falta.mes,&fal[(*n)-1].fecha_falta.ano);

            printf("Hora de la falta: ");
            gets(fal[(*n)-1].hora_falta);

            printf("Descripcion de la falta: ");
            gets(fal[(*n)-1].descrip_falta);

            printf("Estado de la falta: ");
            gets(fal[(*n)-1].estado_falta);

            printf("Identificador del alumno: ");
            gets(fal[(*n)-1].id_alum);

            break;

        case 3:
            for(i=0; i<=*n; i++){
                if(strcmp(cal[i].id_alum,id_alum)==0){
                    printf("%d.-%d/%d/%d-%d-%s-%s-%s\n", i,fal[i].fecha_falta.dia,fal[i].fecha_falta.mes,fal[i].fecha_falta.ano,fal[i].hora_falta,fal[i].descrip_falta,fal[i].estado_falta,fal[i].id_alum );
                }
            }
            printf("Introduce una falta a borrar: ");
            scanf("%d",&op2);

            for(i=op2; i<=*n; i++){
                fal[i].fecha_falta.dia = fal[i+1].fecha_falta.dia;
                fal[i].fecha_falta.mes = fal[i+1].fecha_falta.mes;
                fal[i].fecha_falta.ano = fal[i+1].fecha_falta.ano;

                fal[i].hora_falta = fal[i+1].hora_falta;

                strcpy(fal[i].descrip_falta,fal[i+1].descrip_falta);
                strcpy(fal[i].estado_falta, fal[i+1].estado_falta);
                strcpy(fal[i].id_alum,fal[i+1].id_alum);
            }

            (*n)--;

            fal = (faltas*)realloc(fal,(*n)*sizeof(faltas));
            if(fal == NULL){
                printf("ERROR.\n");
                exit(1);
            }

            break;
    }

    sobreescribir_faltas(fal,n7);

    return fal;
}

void sobreescribir_faltas(faltas *fal,int n){
    int i;
    FILE *f;

    if((f = fopen("faltas.txt","w"))==NULL){
        printf("ERROR.\n");
        exit(1);
    }

    for(i=0; i<=n; i++){
        if(i != n){
            fprintf(f,"%d/%d/%d-%d-%s-%s-%s\n",fal[i].fecha_falta.dia,fal[i].fecha_falta.mes,fal[i].fecha_falta.ano,fal[i].hora_falta,fal[i].descrip_falta,fal[i].estado_falta,fal[i].id_alum);
        }
        else{
            fprintf(f,"%d/%d/%d-%d-%s-%s-%s",fal[i].fecha_falta.dia,fal[i].fecha_falta.mes,fal[i].fecha_falta.ano,fal[i].hora_falta,fal[i].descrip_falta,fal[i].estado_falta,fal[i].id_alum);
        }
    }

    fclose(f);
}
