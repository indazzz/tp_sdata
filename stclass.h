#include<iostream>
using namespace std;
struct pohon{
	string data;
	string jabatan;
	pohon *leftchild;
	pohon *rightchild;
	pohon *parent;
};
pohon *root;
class organisasi{
	public:
		void pohon_baru(string data, string jabatan);
		pohon *tambah_kiri(string data, string jabatan, pohon *parent);
		pohon *tambah_kanan(string data, string jabatan, pohon *parent);
		void inOrder(pohon *parent);
		void postOrder(pohon *parent);
		void preOrder(pohon *parent);
		int size(pohon *parent);
		int height(pohon *parent);
		void deletetree(pohon *parent);
		void clear(pohon *parent);
		void display(pohon *parent, int level);
	private:
		pohon *newpohon;
};
class display{
	public:
		void header();
		void INSERT();
		void TRANSVERSAL();
		void CHARACTERISTIC();
};
