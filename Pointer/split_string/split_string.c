#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int compter_mots(char * str){
    int c=0 , prem=1;
    char *p , *p0;
    if(!*str) return 0;
    p0=str;
    if(!isspace(p0[0]))c++;//pour prevenir si la phrase se commence par un espace
    for(p=str ; *p ; p++){
        printf("p= %s p0 = %s c= %d \n ", p , p0, c);
        if((!isspace(*p)) && (isspace(*p0))) c++;
        p0=p;     
    }
  
    return c;
}

char * copier_remplacer_espace(char *str){
    int i , n =strlen(str);
    char *sortie = malloc((n+1)*sizeof(char));
    for(i = 0 ; i<=n ; i++){
        if(isspace(str[i]))
            sortie[i]=0;
        else sortie[i]=str[i];
    }
    return sortie;
}

char **split_string(char *str, int *nb_mots){
    char **output , *p , *p0;
    int i , ind_mot , n , longueur;
    int nouv_mot = 0 ;
    longueur = strlen(str);
    n = compter_mots(str);
    *nb_mots=n;
    p=copier_remplacer_espace(str);
    if(p[0]!=0)nouv_mot++; //pour prevenir si la phrase se commence par un espace
    output=malloc(n*sizeof(char * ));
    ind_mot=0;
    for(i = 0 ; i<longueur ; i++){
        if(nouv_mot){
            output[ind_mot++]=p+i;
            nouv_mot=0;
        }else if(!p[i] && p[i+1]){
            nouv_mot=1;
        }
    }
    return output;
}
void main(){
    int i , n ;
    char **tab;
    tab = split_string("       Salut  \n les \f amis",&n);
    printf("%d\n", n);
    for(i=0 ; i<n ; i++)
        printf("%s,\n",tab[i]);
    
}
