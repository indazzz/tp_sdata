#include<iostream>
#include"stclass.h"
using namespace std;
void display::header(){
	cout<<"======================================================="<<endl;
	cout<<"||      S T R U K T U R     O R G A N I S A S I      ||"<<endl;
	cout<<"||                                                   ||"<<endl;
	cout<<"||   U N I T   K E G I A T A N   M A H A S I S W A   ||"<<endl;
	cout<<"||                                                   ||"<<endl;
	cout<<"||                 B A D M I N T O N                 ||"<<endl;
	cout<<"-------------------------------------------------------"<<endl;
	cout<<"||             UNIVERSITAS AHMAD DAHLAN              ||"<<endl;
	cout<<"======================================================="<<endl;
}
void organisasi::pohon_baru(string data, string jabatan){
	if(root!=NULL)
		cout<<"!!! KETUA SUDAH TERDAFTAR !!!"<<endl;
	else{
		root=new pohon();
		root->data=data;
		root->jabatan=jabatan;
		root->leftchild=NULL;
		root->rightchild=NULL;
		root->parent=NULL;
		cout<<data<<" berhasil dinobatkan sebagai "<<jabatan<<endl;
	}
}
pohon* organisasi::tambah_kiri(string data, string jabatan, pohon *parent){
	if(root==NULL){
		cout<<"!!! KETUA BELUM TERDAFTAR !!!"<<endl;
		return NULL;
	}
	else{
		if(parent->leftchild!=NULL){
			cout<<parent->data<<" sudah terdaftar sebagai "<<jabatan<<endl;
			return NULL;
		}
		else{
			newpohon=new pohon();
			newpohon->data=data;
			newpohon->jabatan=jabatan;
			newpohon->leftchild=NULL;
			newpohon->rightchild=NULL;
			newpohon->parent=parent;
			parent->leftchild=newpohon;
			cout<<data<<" berhasil dinobatkan sebagai "<<jabatan<<" bagian kiri "<<newpohon->parent->data<<endl;
			return newpohon;
		}
	}
}
pohon* organisasi::tambah_kanan(string data, string jabatan, pohon *parent){
	if(root==NULL){
		cout<<"!!! KETUA BELUM TERDAFTAR !!!"<<endl;
		return NULL;
	}
	else{
		if(parent->rightchild!=NULL){
			cout<<parent->data<<" sudah terdaftar sebagai "<<jabatan<<endl;
			return NULL;
		}
		else{
			newpohon=new pohon();
      		newpohon->data=data;
      		newpohon->jabatan=jabatan;
      		newpohon->leftchild=NULL;
      		newpohon->rightchild=NULL;
      		newpohon->parent=parent;
      		parent->rightchild=newpohon;
      		cout<<data<<" berhasil dinobatkan sebagai "<<jabatan<<" bagian kanan "<<newpohon->parent->data<<endl;
			return newpohon;
    	}
  	}
}
void organisasi::inOrder(pohon *parent){
	if(!root){
		cout<<"!!! MAKE ROOT FIRST !!!"<<endl;
	}
	else{
		if(parent!=NULL){
			inOrder(parent->leftchild);
			cout<<parent->data<<", ";
			inOrder(parent->rightchild);
		}
	}
}
void organisasi::postOrder(pohon *parent){
	if(!root){
		cout<<"!!! MAKE ROOT FIRST !!!"<<endl;
	}
	else{
		if(parent!=NULL){
			postOrder(parent->leftchild);
			postOrder(parent->rightchild);
			cout<<parent->data<<", ";
		}
	}
}
void organisasi::preOrder(pohon *parent){
	if(!root){
		cout<<"!!! MAKE ROOT FIRST !!!"<<endl;
	}
	else{
		if(parent!=NULL){
			cout<<parent->data<<", ";
			preOrder(parent->leftchild);
			preOrder(parent->rightchild);
		}
	}
}
int organisasi::size(pohon *parent){
	if(!root){
    	cout<<"!!! MAKE STRUCTUR DATA FIRST !!!"<<endl;
    	return 0;
  	}
	else{
    	if(!parent){
      		return 0;
    	}
		else{
      		return 1+size( parent->leftchild )+size(parent->rightchild);
    	}
	}
}
int organisasi::height(pohon *parent){
  	if(!root){
  		cout<<"!!! MAKE STRUCTUR DATA FIRST !!!"<<endl;
    	return 0;
    }
	else{
      	if(!parent){
        	return 0;
      	}
		else{
        	int heightKiri=height(parent->leftchild);
        	int heightKanan=height(parent->rightchild);
			if(heightKiri>=heightKanan){
          		return heightKiri+1;
        	}
			else{
          		return heightKanan+1;
        	}
      	}
    }
}
void organisasi::deletetree(pohon *parent){
	if(!root){
  		cout<<"!!! MAKE STRUCTUR DATA FIRST !!!"<<endl;
    }
  	else{
	  	if(parent!=NULL){
      		if(parent!=root){
        		parent->parent->leftchild=NULL;
        		parent->parent->rightchild=NULL;
      		}
      		deletetree(parent->leftchild);
      		deletetree(parent->rightchild);
      		if(parent==root){
        		delete root;
        		root=NULL;
      		}
			else{
        		delete parent;
      		}
		}
	}
}
void organisasi::clear(pohon *parent){
	if(!root){
  		cout<<"!!! MAKE STRUCTUR DATA FIRST !!!"<<endl;
    }
  	else{
    	deletetree(parent);
    	cout<<"!!! TREE HAS DELETED !!!"<< endl;
  	}
}
void organisasi::display(pohon *parent, int level){
    if(parent!=NULL){
        display(parent->rightchild, level+1);
        cout<<"\n\t\t";
        if(parent==root)
        	cout<<"Root -> ";
        for(int i=0; i<level&&parent!=root; i++)
            cout<<"\t\t   ";
        cout<<parent->jabatan<<" : "<<parent->data;
        display(parent->leftchild, level+1);
    }
}
void display::INSERT(){
	organisasi ukmbadminton;
	header();
	pohon *wakil, *divisi, *evaluasipelaporan, *sekertaris, *keuangan, *bendahara1, *bendahara2;
	pohon *koordinasi, *komunikasi, *humas, *kekeluargaan, *kegiatan, *SDM, *PERKAP;
	
	string namaketua;
	cout<<"Masukkan nama KETUA : ";
	cin.ignore();
	getline(cin, namaketua);
	ukmbadminton.pohon_baru(namaketua, "KETUA UKM");
	cout<<endl;
	
	string namawakil;
	cout<<"Masukkan nama WAKIL : ";
	getline(cin, namawakil);
	wakil=ukmbadminton.tambah_kiri(namawakil, "WAKIL", root);
	cout<<endl;
	
	divisi=ukmbadminton.tambah_kiri("DIVISI", "BAGIAN", wakil);
	cout<<endl;
	
	evaluasipelaporan=ukmbadminton.tambah_kiri("EVALUASI DAN PELAPORAN", "BAGIAN", divisi);
	cout<<endl;
	
	string namasekertaris;
	cout<<"Masukkan nama SEKERTARIS : ";
	getline(cin, namasekertaris);
	sekertaris=ukmbadminton.tambah_kiri(namasekertaris, "SEKERTARIS", evaluasipelaporan);
	cout<<endl;
	
	keuangan=ukmbadminton.tambah_kanan("KEUANGAN", "BAGIAN", evaluasipelaporan);
	cout<<endl;
	
	string namabendahara1;
	cout<<"Masukkan nama BENDAHARA 1 : ";
	getline(cin, namabendahara1);
	bendahara1=ukmbadminton.tambah_kiri(namabendahara1, "BENDAHARA 1", keuangan);
	cout<<endl;
	
	string namabendahara2;
	cout<<"Masukkan nama BENDAHARA 2 : ";
	getline(cin, namabendahara2);
	bendahara2=ukmbadminton.tambah_kanan(namabendahara2, "BENDAHARA 2", keuangan);
	cout<<endl;
	
	koordinasi =  ukmbadminton.tambah_kanan("KOORDINASI", "BAGIAN", divisi);
	cout<<endl;
			
	komunikasi = ukmbadminton.tambah_kiri("KOMUNIKASI", "BAGIAN", koordinasi);
	cout<<endl;
	
	string namahumas;
	cout<<"Masukkan nama Humas: ";
	getline(cin, namahumas);
	humas = ukmbadminton.tambah_kiri(namahumas, "HUMAS", komunikasi);
	cout<<endl;
			
	string namakekeluargaan;
	cout<<"Masukkan nama kekeluargaan: ";
	getline(cin, namakekeluargaan);
	kekeluargaan = ukmbadminton.tambah_kanan(namakekeluargaan, "KEKELUARGAAN", komunikasi);
	cout<<endl;
			
	kegiatan = ukmbadminton.tambah_kanan("KEGIATAN", "BAGIAN", koordinasi);
	cout<<endl;
			
	string namasdm;
	cout<<"Masukkan nama SDM: ";
	getline(cin, namasdm);
	SDM = ukmbadminton.tambah_kiri(namasdm, "SDM", kegiatan);
	cout<<endl;
			
	string namaperkap;
	cout<<"Masukkan nama perkap: ";
	getline(cin, namaperkap);
	PERKAP = ukmbadminton.tambah_kanan(namaperkap, "PERKAP", kegiatan);
	cout<<endl;
}
void display::TRANSVERSAL(){
	organisasi ukmbadminton;
	header();
	cout<<"InOrder   : ";
	ukmbadminton.inOrder(root);
	cout<<endl<<endl;
	cout<<"PostOrder : ";
	ukmbadminton.postOrder(root);
	cout<<endl<<endl;
	cout<<"PreOrder  : ";
	ukmbadminton.preOrder(root);
	cout<<endl<<endl;
}
void display::CHARACTERISTIC(){
	organisasi ukmbadminton;
	cout<<"Size Of Structur Organisation         : "<<ukmbadminton.size(root)<<endl;
  	cout<<"Height Of Structur Organisation       : "<<ukmbadminton.height(root)<<endl;
  	cout<<"Average Node Of Structur Organisation : "<<ukmbadminton.size(root)/ukmbadminton.height(root)<<endl;
}
