#include <stdio.h>
#include <stdlib.h>
#include "volcado.h"
#include "profesor.h"

int iniciar_sesion(usuarios*,int ,char *);

int main()
{
    int n1=0, n2=0, n3=0, n4=0,n5=0,n6=0,n7=0;
    char id[4];
    usuarios *us;
    alumnos *al;
    horarios *hor;
    materias *mat;
    matriculas *matri;
    calificaciones *cal;
    faltas *fal;

    volcar(&us,&al,&hor,&mat,&matri,&cal,&fal,&n1,&n2,&n3,&n4,&n5,&n6,&n7);

    if(iniciar_sesion(us, n1,id)){
        menu_profesor(al, hor, mat, matri, cal, fal &n2, &n3, &n4, &n5, &n6, &n7, id);
    }
    else{
        menu_adm(us, al, hor, mat, matri, &n1, &n2, &n3, &n4, &n5, id);
    }

    ///cargar();

    free(us);
    free(al);
    free(hor);
    free(mat);
    free(matri);

    return 0;
}

int iniciar_sesion(usuarios *us, int n1,char *id){
    int aux, aux2, i, tipo_perfil;
    char user[5], pass[9];

    do{
        do{
            printf("=====================================\n");
            printf("*Bienvenido al CUADERNO DEL PROFESOR*\n");
            printf("=====================================\n");

            aux = 0;
            printf("->Usuario: ");
            gets(user);
            for(i=0; i<=n1; i++){
                if((strcmp(user,us[i].usuario))==0){
                    aux = 1;
                    break;
                }
            }
            if(aux == 0){
                printf("Este usuario no existe.\n");
                system("pause");
                system("cls");
            }
        }while(aux == 0);

        aux2 = 0;
        printf("->Contrasena: ");
        gets(pass);

        if((strcmp(pass,us[i].contrasena))==0){
            aux2 = 1;
        }
        else{
            printf("Contrasena incorrecta.\n");
            system("pause");
            system("cls");
        }

    }while(aux2 == 0);

    if((strcmp(us[i].perfil_usuario,"administrador"))==0){
        tipo_perfil = 1;
    }
    else{
        tipo_perfil = 0;
        strcpy(id,us[i].id_usuario);
    }

    return tipo_perfil;
}
