#include<iostream>
#include"functions.h"
#include<windows.h>
#include<conio.h>
using namespace std;
int main(){
	system("color 30");
	menu:
	organisasi ukmbadminton;
	display run;
	int pilihan;
	char pilihan2;
	run.header();
	cout<<":: 1. INSERT                                         ::"<<endl;
	cout<<":: 2. Transversal                                    ::"<<endl;
	cout<<":: 3. Characteristic                                 ::"<<endl;
	cout<<":: 4. DELETE                                         ::"<<endl;
	cout<<":: 5. DISPLAY                                        ::"<<endl;
	cout<<":: 6. EXIT                                           ::"<<endl;
	cout<<"======================================================="<<endl;
	cout<<"Masukkan pilihan : ";
	cin>>pilihan;
	switch(pilihan){
		case 1:
			system("cls");
			run.INSERT();
			cout<<endl<<endl;
			cout<<"Back To Menu? [Y/N] : ";
			cin>>pilihan2;
			if(pilihan2=='Y'||pilihan2=='y'){
				system("cls");
				goto menu;
			}
			else if(pilihan2=='N'||pilihan2=='n') return 0;
			else cout<<"!!! 404 NOT FOUND !!!"<<endl;
			break;
		case 2:
			system("cls");
			run.TRANSVERSAL();
			cout<<endl<<endl;
			cout<<"Back To Menu? [Y/N] : ";
			cin>>pilihan2;
			if(pilihan2=='Y'||pilihan2=='y'){
				system("cls");
				goto menu;
			}
			else if(pilihan2=='N'||pilihan2=='n') return 0;
			else cout<<"!!! 404 NOT FOUND !!!"<<endl;
			break;
		case 3:
			system("cls");
			run.CHARACTERISTIC();
			cout<<endl<<endl;
			cout<<"Back To Menu? [Y/N] : ";
			cin>>pilihan2;
			if(pilihan2=='Y'||pilihan2=='y'){
				system("cls");
				goto menu;
			}
			else if(pilihan2=='N'||pilihan2=='n') return 0;
			else cout<<"!!! 404 NOT FOUND !!!"<<endl;
			break;
		case 4:
			system("cls");
			ukmbadminton.clear(root);
			cout<<endl<<endl;
			cout<<"Back To Menu? [Y/N] : ";
			cin>>pilihan2;
			if(pilihan2=='Y'||pilihan2=='y'){
				system("cls");
				goto menu;
			}
			else if(pilihan2=='N'||pilihan2=='n') return 0;
			else cout<<"!!! 404 NOT FOUND !!!"<<endl;
			break;
		case 5:
			system("cls");
			ukmbadminton.display(root, 1);
			cout<<endl<<endl;
			cout<<"Back To Menu? [Y/N] : ";
			cin>>pilihan2;
			if(pilihan2=='Y'||pilihan2=='y'){
				system("cls");
				goto menu;
			}
			else if(pilihan2=='N'||pilihan2=='n') return 0;
			else cout<<"!!! 404 NOT FOUND !!!"<<endl;
			break;
		case 6:
			return 0;
		default:
			cout<<"!!! 404 NOT FOUND !!!"<<endl;
	}
  	return 0;
}
