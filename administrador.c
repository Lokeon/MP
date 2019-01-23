#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "volcado.h"
#include "administrador.h"

void users(usuarios *, int *);
void alums(alumnos *, matriculas*, int *, int *);
void subjects(materias *, int *);
void timeline(horarios *, int *);

void menu_adm(usuarios *us, alumnos *al, horarios *hor, materias *mat, matriculas *matri, int *n1,  int *n2, int *n3, int *n4, int *n5, char *id_adm){

    int n;

    do{

        printf("=========\n");
        printf("OPCIONES:\n");
        printf("=========\n");
        printf("1-Usuarios.\n");
        printf("2-Alumnos.\n");
        printf("3-Materias.\n");
        printf("4-Horarios.\n");
        printf("-----------\n");
        scanf("%i", &n);

    }while(n<1 || n>4);

    switch(n){

        case 1: users(*us, *n1); break;
        case 2: alums(*al, *matri, *n2, *n5); break;
        case 3: subjects(*mat, *n4); break;
        case 4: timeline(*hor, *n3); break;

    }

}

void users(usuarios *us, int *n1){

    int n, m, i, aux, aux2=0;
    char usaux[6], cadaux[25];
    FILE *f;

    do{
        printf("=========\n");
        printf("USUARIOS:\n");
        printf("=========\n");
        printf("1- Dar de alta un nuevo usuario.\n");
        printf("2- Dar de baja a un usuario.\n");
        printf("3- Modificar un usuario.\n");
        printf("4- Listar los usuarios.\n");
        printf("--------------------------------\n");
        scanf("%i", &n);

    }while(n<1 || n>4);

    switch(n)
    {
    case 1: //Dar de alta

            (*n1)++;

            us=(usuarios*)realloc(us,((*n1)*sizeof(usuarios)));
            if(us==NULL){

                printf("ERROR!\n");

            exit(0);
            }

            printf("Introduzca el ID del nuevo usuario: ");
            scanf("%s", &us[n1].id_usuario);
            fflush(stdin);
            printf("Introduzca el nombre del nuevo usuario: "); //Nombre de la persona
            scanf("%s", &us[n1].nomb_usuario);
            fflush(stdin);
            printf("Introduzca el tipo de usuario: ");
            scanf("%s", &us[n1].perfil_usuario);
            fflush(stdin);
            printf("Introduzca el usuario: "); //Nombre de usuario de la cuenta
            scanf("%s", &us[n1].usuario);
            fflush(stdin);
            printf("Introduzca contraseña: ");
            scanf("%s", &us[n1].contrasena);
            fflush(stdin);

            if((f = fopen("usuarios.txt","a+"))==NULL){

                printf("ERROR no se ha podido abrir el fichero.");

            exit(1);
            }

            fprintf(f,"\n%s-%s-%s-%s-%s", us[n1].id_usuario, us[n1].nomb_usuario, us[n1].perfil_usuario, us[n1].usuario, us[n1].contrasena);

            fclose(f);

            break;

    case 2: //Dar de baja

            do{
                printf("Introduzca el usuario a dar de baja: ");
                scanf("%s", &usaux);

                for(i=0; i<=n1; i++){

                    if(strcmp(us[i].usuario,usaux)==0){
                        aux=i;
                        aux2=1;
                    }
                }
                if(aux2!=1){
                    printf("Usuario erroneo.\n");
                }
            }while(aux2!=1);

            for(i=aux; i<=n1; i++){

                strcpy(us[i].id_usuario, us[i+1].id_usuario);
                strcpy(us[i].nomb_usuario, us[i+1].nomb_usuario);
                strcpy(us[i].perfil_usuario, us[i+1].perfil_usuario);
                strcpy(us[i].usuario, us[i+1].usuario);
                strcpy(us[i].contrasena, us[i+1].contrasena);

            }

            (*n1)--;

            us=(usuarios*)realloc(us,((*n1)*sizeof(usuarios)));
            if(us==NULL){

                printf("ERROR!\n");

            exit(0);
            }

            if((f=fopen("usuarios.txt","w"))==NULL){

                printf("ERROR no se ha podido abrir el fichero.");

            exit(1);
            }

            for(i=0; i<=n1; i++){

                if(i!=n1){
                    fprintf(f,"%s-%s-%s-%s-%s\n", us[i].id_usuario, us[i].nomb_usuario, us[i].perfil_usuario, us[i].usuario, us[i].contrasena);
                }
                else{
                    fprintf(f,"%s-%s-%s-%s-%s", us[i].id_usuario, us[i].nomb_usuario, us[i].perfil_usuario, us[i].usuario, us[i].contrasena);
                }
            }

            fclose(f);

            break;

    case 3: //Modificar
            do{
                printf("Introduzca el usuario a modificar. . .");
                scanf("%s", &usaux);

                for(i=0; i<=n1; i++){

                    if(strcmp(us[i].usuario,usaux)==0){
                        aux=i;
                        aux2=1;
                    }
                }
                if(aux2!=1){
                    printf("Usuario erroneo.\n");
                }
            }while(aux2!=1);

            do{

                printf("¿Que dato desea modificar?\n");
                printf("1-ID usuario.\n");
                printf("2-Nombre del usuario.\n");
                printf("3-Tipo de usuario.\n");
                printf("4-Usuario.\n");
                printf("5-Contrasena.\n");
                printf("--------------------------\n");
                scanf("%i", &m);

                switch(m){

                case 1:

                    printf("Introduzca el nuevo ID para %s. . .", us[aux].nomb_usuario);
                    scanf("%s", &cadaux);
                    strcpy(us[aux].id_usuario, cadaux);
                    break;

                case 2:

                    printf("Introduzca el nuevo nombre de usuario para %s. . .", us[aux].nomb_usuario);
                    scanf("%s", &cadaux);
                    strcpy(us[aux].nomb_usuario, cadaux);
                    break;

                case 3:

                    printf("Introduzca el nuevo tipo de usuario para %s. . .", us[aux].nomb_usuario);
                    scanf("%s", &cadaux);
                    strcpy(us[aux].perfil_usuario, cadaux);
                    break;

                case 4:

                    printf("Introduzca el nuevo usuario para %s. . .", us[aux].nomb_usuario);
                    scanf("%s", &cadaux);
                    strcpy(us[aux].usuario, cadaux);
                    break;

                case 5:

                    printf("Introduzca la nueva contrasena para %s. . .", us[aux].nomb_usuario);
                    scanf("%s", &cadaux);
                    strcpy(us[aux].contrasena, cadaux);
                    break;
                    }

                }while(m<1 || m>5);

            break;

            if((f=fopen("usuarios.txt","w"))==NULL){

                printf("ERROR no se ha podido abrir el fichero.");

            exit(1);
            }

            for(i=0; i<=n1; i++){

                if(i!=n1){
                    fprintf(f,"%s-%s-%s-%s-%s\n", us[i].id_usuario, us[i].nomb_usuario, us[i].perfil_usuario, us[i].usuario, us[i].contrasena);
                }
                else{
                    fprintf(f,"%s-%s-%s-%s-%s", us[i].id_usuario, us[i].nomb_usuario, us[i].perfil_usuario, us[i].usuario, us[i].contrasena);
                }
            }

            fclose(f);


    case 4: //Listar
            for(i=0; i<=n1; i++){

                printf("%s-%s-%s-%s-%s", us[i].id_usuario, us[i].nomb_usuario, us[i].perfil_usuario, us[i].usuario, us[i].contrasena);
                printf("\n");

            }
    break;
    }
}

void alums(alumnos *al, matriculas *matri, int *n2, int *n5){ /**CASE 5 AUN SIN HACER**/

    int n, m, i, j, aux, aux2=0;
    char alaux[7], mateaux[5], mateaux2[5], cadaux[32];
    FILE *f;

    do{
        printf("=========\n");
        printf("USUARIOS:\n");
        printf("=========\n");
        printf("1- Dar de alta un nuevo alumno.\n");
        printf("2- Dar de baja a un alumno.\n");
        printf("3- Modificar un alumno.\n");
        printf("4- Listar los alumnos.\n");
        printf("5- Modificar materias para un alumno.\n");
        printf("-------------------------------------\n");
        scanf("%i", &n);

    }while(n<1 || n>5);

    switch(n)
    {
    case 1: //Dar de alta

            (*n2)++;

            al=(alumnos*)realloc(al,((*n2)*sizeof(alumnos)));
            if(al==NULL){

                printf("ERROR!\n");

            exit(2);
            }

            printf("Introduzca el ID del nuevo alumno: ");
            scanf("%s", &al[n2].id_alum);
            fflush(stdin);
            printf("Introduzca el nombre del nuevo alumno: "); //Nombre de la persona
            scanf("%s", &al[n2].nombre_alum);
            fflush(stdin);
            printf("Introduzca la direccion del alumno: ");
            scanf("%s", &al[n2].direc_alum);
            fflush(stdin);
            printf("Introduzca la localidad del alumno: "); //Nombre de usuario de la cuenta
            scanf("%s", &al[n2].local_alum);
            fflush(stdin);
            printf("Introduzca el curso del alumno: ");
            scanf("%s", &al[n2].curso);
            fflush(stdin);
            printf("Introduzca el grupo al que pertenece el alumno: ");
            scanf("%s", &al[n2].grupo);
            fflush(stdin);

            if((f = fopen("alumnos.txt","a+"))==NULL){

                printf("ERROR no se ha podido abrir el fichero.");

            exit(3);
            }

            fprintf(f,"\n%s-%s-%s-%s-%s-%s", al[n2].id_alum, al[n2].nombre_alum, al[n2].direc_alum, al[n2].local_alum, al[n2].curso, al[n2].grupo);

            fclose(f);

            break;

    case 2: //Dar de baja
            do{

                printf("Introduzca el ID del alumno a dar de baja: ");
                scanf("%s", &alaux);

                for(i=0; i<=n2; i++){

                    if(strcmp(al[i].id_alum,alaux)==0){
                        aux=i;
                        aux2=1;
                    }
                }
                if(aux2!=1){
                    printf("ID erroneo.\n");
                }
            }while(aux2!=1);

            for(i=aux; i<=n2; i++){

                strcpy(al[i].id_alum, al[i+1].id_alum);
                strcpy(al[i].nombre_alum, al[i+1].nombre_alum);
                strcpy(al[i].direc_alum, al[i+1].direc_alum);
                strcpy(al[i].local_alum, al[i+1].local_alum);
                strcpy(al[i].curso, al[i+1].curso);
                strcpy(al[i].grupo, al[i+1].grupo);

            }

            (*n1)--;

            al=(alumnos*)realloc(al,((*n2)*sizeof(alumnos)));
            if(al==NULL){

                printf("ERROR!\n");

            exit(2);
            }

            if((f=fopen("alumnos.txt","w"))==NULL){

                printf("ERROR; no se ha podido abrir el fichero.");

            exit(3);
            }

            for(i=0; i<=n2; i++){

                if(i!=n2){
                    fprintf(f,"%s-%s-%s-%s-%s-%s\n", al[i].id_alum, al[i].nombre_alum, al[i].direc_alum, al[i].local_alum, al[i].curso, al[i].grupo);
                }
                else{
                    fprintf(f,"%s-%s-%s-%s-%s-%s", al[i].id_alum, al[i].nombre_alum, al[i].direc_alum, al[i].local_alum, al[i].curso, al[i].grupo);
                }
            }

            fclose(f);

            break;

    case 3: //Modificar
            do{
                printf("Introduzca el ID del alumno a modificar. . .");
                scanf("%s", &alaux);

                for(i=0; i<=n2; i++){

                    if(strcmp(al[i].id_alum,alaux)==0){
                        aux=i;
                        aux2=1;
                    }
                }
                if(aux2!=1){
                    printf("ID erroneo.\n");
                }
            }while(aux2!=1);

            do{

                printf("¿Que dato desea modificar?\n");
                printf("1-ID alumno.\n");
                printf("2-Nombre del alumno.\n");
                printf("3-Direccion del alumno.\n");
                printf("4-Localidad del alumno.\n");
                printf("5-Curso al que pertenece el alumno.\n");
                printf("6-Grupo al que pertenece el alumno.\n");
                printf("-----------------------------------\n");
                scanf("%i", &m);

                switch(m){

                case 1:

                    printf("Introduzca el nuevo ID para %s. . .", al[aux].nombre_alum);
                    scanf("%s", &cadaux);
                    strcpy(al[aux].id_alum, cadaux);
                    break;

                case 2:

                    printf("Introduzca el nuevo nombre del alumno %s. . .", al[aux].nombre_alum);
                    scanf("%s", &cadaux);
                    strcpy(al[aux].nombre_alum, cadaux);
                    break;

                case 3:

                    printf("Introduzca la nueva direccion de %s. . .", al[aux].nombre_alum);
                    scanf("%s", &cadaux);
                    strcpy(al[aux].direc_alum, cadaux);
                    break;

                case 4:

                    printf("Introduzca la nueva localidad de %s. . .", al[aux].nombre_alum);
                    scanf("%s", &cadaux);
                    strcpy(al[aux].local_alum, cadaux);
                    break;

                case 5:

                    printf("Introduzca el nuevo curso para %s. . .", al[aux].nombre_alum);
                    scanf("%s", &cadaux);
                    strcpy(al[aux].curso, cadaux);
                    break;

                case 6:

                    printf("Introduzca el nuevo grupo para %s. . .", al[aux].nombre_alum);
                    scanf("%s", &cadaux);
                    strcpy(al[aux].grupo, cadaux);
                    break;
                    }

                }while(m<1 || m>6);

            if((f=fopen("alumnos.txt","w"))==NULL){

                printf("ERROR no se ha podido abrir el fichero.");

            exit(3);
            }

            for(i=0; i<=n2; i++){

                if(i!=n2){
                    fprintf(f,"%s-%s-%s-%s-%s-%s\n", al[i].id_alum, al[i].nombre_alum, al[i].direc_alum, al[i].local_alum, al[i].curso, al[i].grupo);
                }
                else{
                     fprintf(f,"%s-%s-%s-%s-%s-%s", al[i].id_alum, al[i].nombre_alum, al[i].direc_alum, al[i].local_alum, al[i].curso, al[i].grupo);
                }
            }

            fclose(f);

            break;

    case 4: //Listar
        for(i=0; i<=n2; i++){

            printf("%s-%s-%s-%s-%s-%s", al[i].id_alum, al[i].nombre_alum, al[i].direc_alum, al[i].local_alum, al[i].curso, al[i].grupo);
            printf("\n");
        }

        break;

    case 5:
            do{

                printf("Introduzca el ID del alumno. . .");
                scanf("%s", &alaux);

                for(i=0; i<=n2; i++){
                    if(strcmp(al[i].id_alum,alaux)==0){
                        aux2=1;
                    }
                }
                if(aux2!=1){
                    printf("ID erroneo.\n");
                }
            }while(aux2!=1);

            do{
                printf("Opciones:\n");
                printf("1- Mostrar lista de materias.\n");
                printf("2- Cambiar matriculas.\n");
                printf("3- Eliminar matricula.\n");
                printf("4- Crear nueva matricula.\n");
                printf("----------------------------\n");
                scanf("%i", &m);

                switch(m){

                    case 1:

                        for(i=0; i<=n5; i++){
                            if(strcmp(matri[i].id_alum,alaux)==0){
                                printf("Matricula: %s-", matri[i].id_materia);
                            }
                        }
                        break;

                    case 2:

                        for(i=0; i<=n5; i++){
                            if(strcmp(matri[i].id_alum,alaux)==0){
                                printf("Introduce el ID de materia a cambiar. . .");
                                scanf("%s", &mateaux);
                                    if(strcmp(matri[i].id_materia, mateaux)==0){
                                        printf("Introduce el ID de la nueva materia. . .");
                                        scanf("%s", &mateaux2);
                                        strcpy(matri[i].id_materia, mateaux2);
                                    }
                            }
                        }
                        break;

                    case 3:

                        for(i=0; i<=n5; i++){
                            if(strcmp(matri[i].id_alum,alaux)==0){
                                printf("Introduzca el ID de la materia a eliminar. . .");
                                scanf("%s", mateaux);
                                    if(strcmp(matri[i].id_materia, mateaux)==0){
                                        aux=i;
                                    }
                            }
                        }

                        for(i=0; i<=n5; i++){
                            strcpy(matri[aux].id_materia, matri[aux+1].id_materia);
                            strcpy(matri[aux].id_alum, matri[aux+1].id_alum);
                        }

                        (*n5)--;

                        matri=(matriculas*)realloc(matri,((*n5)*sizeof(matriculas)));
                        if(matri==NULL){

                            printf("ERROR!\n");

                        exit(0);
                        }

                        if((f=fopen("matriculas.txt","w"))==NULL){

                            printf("ERROR; no se ha podido abrir el fichero.");

                        exit(3);
                        }

                        for(i=0; i<=n5; i++){

                        if(i!=n5){
                            fprintf(f,"%s-%s\n", matri[i].id_materia, matri[i].id_alum);
                            }
                        else{
                            fprintf(f,"%s-%s", matri[i].id_materia, matri[i].id_alum);
                            }
                        }

                        fclose(f);

                        break;

                    case 4:

                        (*n5)++;

                        matri=(matriculas*)realloc(matri,((*n5)*sizeof(matriculas)));
                            if(matri==NULL){

                                printf("ERROR!\n");

                        exit(2);
                        }

                        strcpy(matri[n5].id_alum, alaux);
                        printf("Introduzca el ID de la nueva materia para %s. . .", alaux);
                        scanf("%s", &matri[5].id_materia);

                        if((f=fopen("matriculas.txt","a+"))==NULL){

                            printf("ERROR; no se ha podido abrir el fichero.");

                        exit(3);
                        }

                        fprintf(f,"\n%s-%s", matri[n5].id_materia, matri[n5].id_alum);

                        fclose(f);

                        break;
                }


            }while();

    break;
    }
}

void subjects(materias *mat , int *n4){

	int n, m, i, aux, aux2=0;
	char mataux[50], cadaux[52];
    FILE *f;

     do{
        printf("=========\n");
        printf("MATERIAS:\n");
        printf("=========\n");
        printf("1- Dar de alta una nueva materia.\n");
        printf("2- Dar de baja a una materia.\n");
        printf("3- Modificar una materia.\n");
        printf("4- Listar las materias.\n");
        printf("---------------------------------\n");
        scanf("%i", &n);

    }while(n<1 || n>4);

	switch(n)
    {
    case 1:

            (*n4)++;

            mat=(materias*)realloc(mat,((*n1)*sizeof(materias)));
            if(mat==NULL){

                printf("ERROR!\n");

            exit(4);
            }

            printf("Introduzca el ID de la nueva materia: ");
            scanf("%s", &mat[n4].id_materia);
            fflush(stdin);
            printf("Introduzca el nombre de la nueva materia: "); //Nombre de la persona
            scanf("%s", &mat[n4].nombre_materia);
            fflush(stdin);
            printf("Introduzca la abreviatura nueva de la materia: ");
            scanf("%s", &us[n4].abrev_materia);
            fflush(stdin);

			if((f = fopen("materias.txt","a+"))==NULL){

                printf("ERROR no se ha podido abrir el fichero.");

            exit(5);
            }

            fprintf(f,"\n%s-%s-%s", mat[n4].id_materia, mat[n4].nombre_materia, mat[n4].abrev_materia);

            fclose(f);

            break;

    case 2:
            do{
            printf("Introduzca la materia a dar de baja: ");
            scanf("%s", &mataux);

            for(i=0; i<=n4; i++){
                if(strcmp(mat[i].nombre_materia,mataux)==0){
                    aux=i;
                    aux2=1;
                }
            }
                if(aux2!=1){
                    printf("Materia erronea.\n");
                }
            }while(aux2!=1);

            for(i=aux; i<=n4; i++){

                strcpy(mat[i].id_materia, mat[i+1].id_materia);
                strcpy(mat[i].nombre_materia, mat[i+1].nombre_materia);
                strcpy(mat[i].abrev_materia, mat[i+1].abrev_materia);

			   }

            (*n4)--;

            mat=(materias*)realloc(mat,((*n4)*sizeof(materias)));
            if(mat==NULL){

                printf("ERROR!\n");

            exit(4);
            }

            if((f=fopen("materias.txt","w"))==NULL){

                printf("ERROR no se ha podido abrir el fichero.");

            exit(5);
            }

            for(i=0; i<=n4; i++){

                if(i!=n4){
                    fprintf(f,"%s-%s-%s\n", mat[i].id_materia, mat[i].nombre_materia, mat[i].abrev_materia);
                }
                else{
                    fprintf(f,"%s-%s-%s", mat[i].id_materia, mat[i].nombre_materia, mat[i].abrev_materia);
                }
            }

            fclose(f);

            break;

    case 3:
            do{
                printf("Introduzca la materia a modificar. . .");
                scanf("%s", &mataux);

                for(i=0; i<=n4; i++){

                    if(strcmp(mat[i].nombre_materia,mataux)==0){
                    aux=i;
                    aux2=1;
                    }
                }
                if(aux2!=1){
                    printf("Materia erronea.\n");
                }
            }while(aux2!=1);

            do{
            printf("¿Que dato desea modificar?\n");
            printf("1-ID materia.\n");
            printf("2-Nombre de la materia.\n");
            printf("3-Abreviatura de la materia.\n");
            printf("----------------------------\n");
            scanf("%i", &m);

            switch(m){

            case 1:

                printf("Introduzca el nuevo ID para %s. . .", mat[aux].nombre_materia);
                scanf("%s", &cadaux);
                strcpy(mat[aux].id_materia, cadaux);
                break;

            case 2:

                printf("Introduzca el nuevo nombre de la materia para %s. . .", mat[aux].nombre_materia);
                scanf("%s", &cadaux);
                strcpy(mat[aux].nombre_materia, cadaux);
                break;

            case 3:

                printf("Introduzca la nueva abreviatura de la materia para %s. . .", mat[aux].nombre_materia);
                scanf("%s", &cadaux);
                strcpy(mat[aux].abrev_materia, cadaux);
                break;

                }
            }while(m<1 || m>3);

            if((f=fopen("materias.txt","w"))==NULL){

                printf("ERROR no se ha podido abrir el fichero.");

            exit(5);
            }

            for(i=0; i<=n4; i++){

                if(i!=n4){
                    fprintf(f,"%s-%s-%s\n", mat[i].id_materia, mat[i].nombre_materia, mat[i].abrev_materia);
                }
                else{
                    fprintf(f,"%s-%s-%s", mat[i].id_materia, mat[i].nombre_materia, mat[i].abrev_materia);
                }
            }

            fclose(f);


    case 4:
            for(i=0; i<=n4; i++){

                printf("%s-%s-%s", mat[i].id_materia, mat[i].nombre_materia, mat[i].abrev_materia);
                printf("\n");

            }
    break;
    }
}

void timeline(horarios *hor, int *n3) {

	int n, m, i, j, aux, aux2=0, aux3;
	char horaux[50], cadaux[12];
    FILE *f;

     do{
        printf("=========\n");
        printf("HORARIOS:\n");
        printf("=========\n");
        printf("1- Añadir horas.\n");
        printf("2- Eliminar las horas.\n");
        printf("3- Modificar los horarios.\n");
        printf("4- Listar los horarios.\n");
        printf("--------------------------\n");
        scanf("%i", &n);

    }while(n<1 || n>4);

    switch(n){

    case 1:
            (*n3)++;
            hor=(horarios*)realloc(hor,((*n3)*sizeof(horarios)));
            if(hor==NULL){

                printf("ERROR!\n");

            exit(4);
            }
            do{
                printf("Introduzca el ID del profesor al que añadir horas. . .");
                scanf("%s", &cadaux);

                for(i=0; i<=n3; i++){
                    if(strcmp(hor[i].id_profesor,cadaux)==0){
                        aux2=1;
                    }
                }
                if(aux2!=1){
                    printf("ID erroneo.\n");
                }
            }while(aux2!=1);

            strcpy(hor[n3].id_profesor, cadaux);
            printf("Introduzca el nuevo dia de clase. . .");
            scanf("%i", &hor[n3].dia_clase);
            printf("Introduzca la hora de clase. . .");
            scanf("%i", &hor[n3].hora_clase);
            printf("Introduzca el id de la materia. . .");
            scanf("%s", &hor[n3].id_materia);
            printf("Introduzca el grupo de la clase. . .");
            scanf("%s", &hor[n3].grupo);

			if((f = fopen("materias.txt","a+"))==NULL){

                printf("ERROR no se ha podido abrir el fichero.");

            exit(5);
            }

            fprintf(f,"\n%s-%s-%s-%s-%s", hor[n3].id_profesor, hor[n3].dia_clase, hor[n3].hora_clase, hor[n3].id_materia, hor[n3].grupo);

            fclose(f);

            break;

    case 2:

            do{
                printf("Introduzca el ID del profesor cuyas horas quiera eliminar . . .");
                scanf("%s", &cadaux);

                for(i=0; i<=n3; i++){
                    if(strcmp(hor[i].id_profesor,cadaux)==0){
                        aux2=1;
                        printf("Introduzca el dia cuyas horas quiera eliminar del profesor %s. . .", cadaux);
                        scanf("%i", &aux);
                        if(hor[i].dia_clase==aux){
                            printf("Introduzca la hora que quera eliminar para el dia %i. . .", aux);
                            scanf(&aux3);
                            if(hor[i].hora_clase==aux3){
                                for(j=i; j<=n3; j++){

                                    strcpy(hor[j].id_profesor, hor[j+1].id_profesor);
                                    strcpy(hor[j].dia_clase, hor[j+1].dia_clase);
                                    strcpy(hor[j].hora_clase, hor[j+1].hora_clase);
                                    strcpy(hor[j].id_materia, hor[j+1].id_materia);
                                    strcpy(hor[j].grupo, hor[j+1].grupo);
                                }

                                (*n3)--;
                                hor=(horarios*)realloc(hor,((*n3)*sizeof(horarios)));
                                if(hor==NULL){

                                    printf("ERROR!\n");

                                    exit(4);
                                }
                            }
                        }
                    }
                }
                if(aux2!=1){
                    printf("ID erroneo.\n");
                }
            }while(aux2!=1);

            if((f=fopen("horarios.txt","w"))==NULL){

                printf("ERROR no se ha podido abrir el fichero.");

            exit(5);
            }

            for(i=0; i<=n3; i++){

                if(i!=n3){
                    fprintf(f,"%s-%s-%s-%s-%s\n", hor[i].id_profesor, hor[i].dia_clase, hor[i].hora_clase, hor[i].id_materia, hor[i].grupo);
                }
                else{
                    fprintf(f,"%s-%s-%s-%s-%s", hor[i].id_profesor, hor[i].dia_clase, hor[i].hora_clase, hor[i].id_materia, hor[i].grupo);
                }
            }

            fclose(f);

            break;

    case 3:
            do{
                printf("Introduzca el ID del profesor cuyo horario quiera modificar . . .");
                scanf("%s", &cadaux);

                for(i=0; i<=n3; i++){

                    if(strcmp(hor[i].id_profesor,cadaux)==0){
                        aux=i;
                        aux2=1;
                    }
                }
                if(aux2!=1){
                    printf("ID erroneo.\n");
                }
            }while(aux2!=1);

            do{

            printf("¿Que dato desea modificar?\n");
            printf("1-ID profesor.\n");
            printf("2-Dia de clase.\n");
            printf("3-Hora de clase.\n");
            printf("4-ID materia.\n");
            printf("5-Grupo.\n");
            printf("--------------------------\n");
            scanf("%i", &m);

            switch(m){

            case 1:

                printf("Introduzca el nuevo ID para %s. . .", hor[aux].id_profesor);
                scanf("%s", &horaux);
                strcpy(hor[aux].id_profesor, horaux);
                break;

            case 2:

                printf("Introduzca el nuevo dia de clase para %s. . .", hor[aux].id_profesor);
                scanf("%i", &hor[aux].dia_clase);
                break;

            case 3:

                printf("Introduzca la nueva hora de clase para %s. . .", hor[aux].id_profesor);
                scanf("%i", &hor[aux].hora_clase);
                break;

            case 4 :

            	printf("Introduzca el nuevo ID de materia para %s. . .", hor[aux].id_profesor);
                scanf("%s", &horaux);
                strcpy(hor[aux].id_materia, horaux);
                break;

             case 5 :
			    printf("Introduzca el nuevo grupo de clase para %s. . .", hor[aux].id_profesor);
                scanf("%s", &horaux);
                strcpy(hor[aux].grupo, horaux);
                break;
                }

            }while(m<1 || m>5);

            if((f=fopen("materias.txt","w"))==NULL){

                printf("ERROR no se ha podido abrir el fichero.");

            exit(5);
            }

            for(i=0; i<=n3; i++){

                if(i!=n3){
                    fprintf(f,"%s-%s-%s-%s-%s\n", hor[i].id_profesor, hor[i].dia_clase, hor[i].hora_clase, hor[i].id_materia, hor[i].grupo);
                }
                else{
                    fprintf(f,"%s-%s-%s-%s-%s", hor[i].id_profesor, hor[i].dia_clase, hor[i].hora_clase, hor[i].id_materia, hor[i].grupo);
                }
            }

            fclose(f);


    case 4:
            for(i=0; i<=n3; i++){

                printf("%s-%s-%s-%s-%s", hor[i].id_profesor, hor[i].dia_clase, hor[i].hora_clase, hor[i].id_materia, hor[i].grupo);
                printf("\n");

            }
    break;
    }
}
