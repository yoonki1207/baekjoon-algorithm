#include<stdio.h>

int doubtCroatia(char c);
int isCroatia(char *s);
char croatia[8][4] = {"c=","c-","dz=","d-","lj","nj","s=","z="};
int main(){
	char word[105]={0,};
	int i=0, letters=0;
	scanf("%s",word);
//	printf("Start : %X\n",word+i);
	while(word[i]!=0){
		if(doubtCroatia(word[i])){
			int k=isCroatia(&word[i]);
			if(k){
				letters++;
				i+=k;
			}else{
				letters++;
				i++;
			}
		}else{
			// not Croatia. So add letters one
			letters++;
			i++;
		}
	}
	printf("%d\n",letters);
	//printf("%X\n",word+i);
}

int doubtCroatia(char c){
	int i,j;
	for(i=0;i<8;i++){
		if(c==(char)croatia[i][0]){
			return 1;
		}
	}
	return 0;
}

int isCroatia(char *s){
//	printf("%X\n",s);
	if(s[1]=='z'){// 3 letters
		int i=0;
		for(i=0;i<3;i++){
			if(croatia[2][i]!=s[i]){
				return 0;
			}
		}
		return 3;
	}else{// 2 letters
		int i;
		for(i=0;i<8;i++){
			if(croatia[i][1]==s[1] && croatia[i][0]==s[0]&& i!=2){
				return 2;
			}
		}
		return 0;
	}
}
