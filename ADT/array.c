//Vivianni
//13517060
//12 September 2018
//ADT Array

#include "boolean.h"
#include "array.h"
#include <stdio.h>

void MakeEmpty (TabInt * T){
	Neff(*T)=0;
}

int NbElmtArr (TabInt T){
	return Neff(T);
}

int MaxNbEl (TabInt T){
	return IdxMax;
}

IdxType GetFirstIdx (TabInt T){
	return IdxMin;
}

IdxType GetLastIdx (TabInt T){
	return Neff(T);
}

boolean IsIdxEff (TabInt T, IdxType i){
	return (i>=GetFirstIdx(T)) && (i<=GetLastIdx(T));	
}

boolean IsEmpty (TabInt T){
	return (Neff(T)==0);
}

boolean IsFull (TabInt T){
	return (Neff(T)==IdxMax);	
}

void BacaIsi (TabInt * T){
	int N,i;
	while (N<0 || N>MaxNbEl(*T)){
		scanf("%d",&N);
	}
	if (N==0){
		MakeEmpty(&(*T));
	} 
	else{
		for (i=IdxMin;i<=N;i++){
			scanf("%d",&ElmtArr(*T,i));
		}
		Neff(*T)=N;
	}
}

void BacaIsiTab (TabInt * T){
	int x,i;
	scanf("%d",&x);
	if (x=IdxUndef){
		MakeEmpty(&(*T));
	} 
	else{
		i=IdxMin;
		while (x!=IdxUndef && IsIdxValid(*T,i)){
			ElmtArr(*T,i)=x;
			i++;
			scanf("%d",&x);
		}
		if (i>IdxMax){
			Neff(*T)=i-1;
		}
		else{
			Neff(*T)=i;
		}
	}
}

void TulisIsi (TabInt T){
	IdxType i;
	if (Neff(T)==0){
		printf("Tabel Kosong\n");
	}
	else{
		for(i=IdxMin;i<=Neff(T);i++){
			printf("[%d]%d\n", i, ElmtArr(T,i));
		}
	}
}

void TulisIsiTab (TabInt T){
	IdxType i;
	if (Neff(T)==0){
		printf("[]");
	}
	else{
		printf("[");
		for(i=IdxMin;i<=Neff(T);i++){
			printf("%d,", ElmtArr(T,i));
		}
		printf("]");
	}
}

TabInt PlusTab (TabInt T1, TabInt T2){
	TabInt T3;
	int i;
	for (i=IdxMin;i<=Neff(T1);i++){
		ElmtArr(T3,i)=ElmtArr(T1,i)+ElmtArr(T2,i);
	}
	Neff(T3)=Neff(T1);
	return T3;
}

TabInt MinusTab (TabInt T1, TabInt T2){
	TabInt T3;
	int i;
	for (i=IdxMin;i<=Neff(T1);i++){
		ElmtArr(T3,i)=ElmtArr(T1,i)-ElmtArr(T2,i);
	}
	Neff(T3)=Neff(T1);
	return T3;	
}

TabInt KaliTab (TabInt T1, TabInt T2){
	TabInt T3;
	int i;
	for (i=IdxMin;i<=Neff(T1);i++){
		ElmtArr(T3,i)=ElmtArr(T1,i)*ElmtArr(T2,i);
	}
	Neff(T3)=Neff(T1);
	return T3;	
}

TabInt KaliKons (TabInt Tin, ElType c){
	TabInt Tout;
	int i;
	for (i=IdxMin;i<=Neff(Tin);i++){
		ElmtArr(Tout,i)=ElmtArr(Tin,i)*c;
	}
	Neff(Tout)=Neff(Tin);
	return Tout;	
}

boolean IsEQ (TabInt T1, TabInt T2){
	int i;
	boolean EQ;
	i=IdxMin;
	EQ = true;
	if(Neff(T1)!=Neff(T2)){
		return (!EQ);
	}
	else{
		while(i<=GetLastIdx(T1) && EQ){
			if(ElmtArr(T1,i)==ElmtArr(T2,i)){
				i++;
			}
			else{
				EQ=false;
			}
		}
		return EQ;
	}
}

boolean IsLess (TabInt T1, TabInt T2){
	int max;
	int i=IdxMin;
	if (Neff(T1)>Neff(T2)){
		max = Neff(T1);
	}
	else{
		max=Neff(T2);
	}
	while (i<=max &&  ElmtArr(T1,i)<ElmtArr(T2,i)){
		i++;
	}
	if(i==max+1){
		return true;
	}

}

IdxType Search1 (TabInt T, ElType X){
	int i;
	i=IdxMin;
	if(IsEmpty(T)){
		return IdxUndef;
	}
	else{
		while ((i<=Neff(T))&&(ElmtArr(T,i)!=X)){
			i++;
		}
		if (ElmtArr(T,i)==X){
			return i;
		}
		else{
			return IdxUndef;
		}
	}	
}

IdxType Search2 (TabInt T, ElType X){
	int i;
	i=IdxMin;
	boolean Found;
	Found = false;
	if(IsEmpty(T)){
		return IdxUndef;
	}
	else{
		while ((i<=Neff(T))&& (~Found)){
			Found=(ElmtArr(T,i)==X);
			i++;
		}	
		if (Found){
			return i-1;
		}else{
			return IdxUndef;
		}
	}
}

boolean SearchB (TabInt T, ElType X){
	return (Search2(T,X)!=IdxUndef);
}

boolean SearchSentinel (TabInt T, ElType X){
	int i=GetLastIdx(T);
	ElmtArr(T,0)=X;
	while(ElmtArr(T,i)!=X){
		i--;
	}
	return (i!=0);
}

ElType ValMax (TabInt T){
	return ElmtArr(T,IdxMaxTab(T));
}

ElType ValMin (TabInt T){
	return ElmtArr(T,IdxMinTab(T));
}

IdxType IdxMaxTab (TabInt T){
	int imax = GetFirstIdx(T);
	int i;
	for(i=IdxMin+1;i<=Neff(T);i++){
		if(ElmtArr(T,i)>ElmtArr(T,imax)){
			imax=i;
		}
	}
	return imax;	
}

IdxType IdxMinTab (TabInt T){
	int imin = GetFirstIdx(T);
	int i;
	for(i=IdxMin+1;i<=Neff(T);i++){
		if(ElmtArr(T,i)<ElmtArr(T,imin)){
			imin=i;
		}
	}
	return imin;	
}

void CopyTab (TabInt Tin, TabInt * Tout){
	int i;
	Neff(*Tout)=Neff(Tin);
	for(i=IdxMin;i<=GetLastIdx(Tin);i++){
		ElmtArr(*Tout,i)=ElmtArr(Tin,i);
	}
}

TabInt InverseTab (TabInt T){
	int i;
	ElType temp;
	if (Neff(T)==0){
		return T;
	}
	else{
		for(i=1;i<=(Neff(T)/2);i++){
			temp=ElmtArr(T,(GetFirstIdx(T)+i-1));
			ElmtArr(T,(GetFirstIdx(T)+i-1))=ElmtArr(T,(GetLastIdx(T)+i-1));
			ElmtArr(T,(GetLastIdx(T)+i-1))=temp;
		}
	}
	return T;
}

boolean IsSimetris (TabInt T){
	boolean simetris = true;
	int i=1;
	if (Neff(T)==0){
		return simetris;
	}

	while (i<=(Neff(T)/2) && simetris){
		simetris=(ElmtArr(T,(GetFirstIdx(T)+i-1))==ElmtArr(T,(GetLastIdx(T)+i-1)));
	}
	return simetris;
}

void MaxSortDesc (TabInt * T){
	IdxType i;
	int N;
	ElType temp;
	boolean tukar = true;
	N=GetLastIdx(*T);
	while (tukar){
		tukar = false;
		for(i=GetFirstIdx(*T);i<=N-1;i++){
			if (ElmtArr(*T,i+1) > ElmtArr(*T,i)){
				temp = ElmtArr(*T,i+1);
				ElmtArr(*T,i+1)=ElmtArr(*T,i);
				ElmtArr(*T,i)=temp;
				tukar=true;
			}
		}
		N--;
	}
}

void InsSortAsc (TabInt * T){
	IdxType i,j;
	ElType temp;
	for(i=GetFirstIdx(*T)+1;i<=GetLastIdx(*T);i++){
		temp=ElmtArr(*T,i);
		j=i;
		while ((j>1) && (temp<ElmtArr(*T,j-1))){
			ElmtArr(*T,j)=ElmtArr(*T,j-1);
			j--;
		}
		ElmtArr(*T,j)=temp;
	}
}

void AddAsLastEl (TabInt * T, ElType X){
	ElmtArr(*T,GetLastIdx(*T)+1)=X;
	Neff(*T)++;
}

void AddEli (TabInt * T, ElType X, IdxType i){
	IdxType j;
	for(j=GetLastIdx(*T);j>=i;j--){
		ElmtArr(*T,j+1)=ElmtArr(*T,j);
	}
	ElmtArr(*T,i)=X;
	Neff(*T)++;
}

void DelLastEl (TabInt * T, ElType * X){
	Neff(*T)--;
}

void DelEli (TabInt * T, IdxType i, ElType * X){
	IdxType j;
	for(j=i;j<=GetLastIdx(*T)-1;j++){
		ElmtArr(*T,j)=ElmtArr(*T,j+1);
	}
	Neff(*T)--;
}

void AddElUnik (TabInt * T, ElType X){
	if (!SearchSentinel(*T,X)){
		ElmtArr(*T,GetLastIdx(*T)+1)=X;
		Neff(*T)++;
	}
	else{
		printf("nilai sudah ada\n");
	}
}

IdxType SearchUrut (TabInt T, ElType X){
	return Search1(T,X);
}

ElType MaxUrut (TabInt T){
	return(T,GetLastIdx(T));
}

ElType MinUrut (TabInt T){
	return(T,GetFirstIdx(T));
}

void MaxMinUrut (TabInt T, ElType * Max, ElType * Min){
	*Max=MaxUrut(T);
	*Min=MinUrut(T);
}

void Add1Urut (TabInt * T, ElType X){
	int i=IdxMin;
	if (!(IsFull(*T)))
	{
		while(X>ElmtArr(*T,i) && X<ElmtArr(*T,i+1))
		{
		   i++;
		}
		AddEli(&(*T),X,i);
	}
}

void Del1Urut (TabInt * T, ElType X){
	if (Search1(*T,X)!=IdxUndef){
		DelEli(&(*T),Search1(*T,X),&X);
	}
}