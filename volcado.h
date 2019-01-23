#ifndef VOLCADO_H_INCLUDED
#define VOLCADO_H_INCLUDED

typedef struct{
    char id_usuario[4];
    char nomb_usuario[21];
    char perfil_usuario[21];
    char usuario[6];
    char contrasena[9];
}usuarios;

typedef struct{
    char id_alum[7];
    char nombre_alum[20];
    char direc_alum[30];
    char local_alum[30];
    char curso[30];
    char grupo[10];
}alumnos;

typedef struct{
    char id_profesor[4];
    int dia_clase;
    int hora_clase;
    char id_materia[5];
    char grupo[11];
}horarios;

typedef struct{
    char id_materia[5];
    char nombre_materia[50];
    char abrev_materia[4];
}materias;

typedef struct{
    char id_materia[5];
    char id_alum[7];
}matriculas;

typedef struct{
    int dia;
    int mes;
    int ano;
}fecha;

typedef struct{
    fecha fecha_calif;
    char descrip_calif[31];
    char id_materia[5];
    char id_alum[7];
    int valor_calif;
}calificaciones;

typedef struct{
    fecha fecha_falta;
    int hora_falta;
    char descrip_falta[31];
    char estado_falta[20];
    char id_alum[7];
}faltas;

void volcar(usuarios **, alumnos **, horarios **, materias **, matriculas **, calificaciones**, faltas**, int *, int *, int *, int *, int *, int *,int *);

#endif // VOLCADO_H_INCLUDED
