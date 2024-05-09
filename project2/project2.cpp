#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class NhanVien
{
public:
	string maNV, hoTen, gT, diaChi;
	int tuoi;
public:
	
	void Nhap() {
		cout << "Nhap ma nhan vien: "; getline(cin, maNV);
		cout << "Nhap ho ten: "; getline(cin, hoTen);
		cout << "Nhap tuoi: "; cin >> tuoi;
		cin.ignore();
		cout << "Nhap gioi tinh: "; getline(cin, gT);
		cout << "Nhap dia chi: "; getline(cin, diaChi);
	}
	void Xuat() {
		cout << endl;
		cout << "Ma nv: " << maNV << "  " << "Ho ten: " << hoTen << "  " << "Tuoi: " << tuoi << "  " << "Gioi tinh: " << gT<< "  " << "Dia chi: " << diaChi << endl;
	}
	/*string getMaNV() {
		return maNV;
	}*/
	void Load_file(NhanVien ds[], int& n) {
		//khai bao bien file
		fstream file;

		//mo file
		file.open("index.txt", ios_base::in);

		//lam viec voi file
		int sl;
		file >> sl;
		file.ignore();
		for (int i = 0; i < sl; i++)
		{
			NhanVien a;
			getline(file, a.maNV, ',');
			getline(file, a.hoTen, ',');
			file >> a.tuoi;
			file.ignore();
			getline(file, a.gT, ',');
			getline(file, a.diaChi, ',');

			ds[n++] = a;
		}

		//dong file
		file.close();
	}
};

class QLNV
{
public:
	NhanVien a;
	void NhapTT(NhanVien ds[], int &n) {
		cin.ignore();
		for (int i = 0; i < n; i++)
		{
			cout << endl;
			ds[i].Nhap();
		}
	}
	void XuatTT(NhanVien ds[], int &n) {
		for (int i = 0; i < n; i++)
		{
			ds[i].Xuat();
		}
	}
	//void Load_file(NhanVien ds[], int& n) {
	//	//khai bao bien file
	//	fstream file;
	//	//mo file
	//	file.open("index.txt", ios_base::in);
	//	//lam viec voi file
	//	file >> n;
	//	NhanVien a;
	//	getline(file, a.maNV, ',');
	//	//dong file
	//	file.close();
	//}
};

int main() {
	NhanVien ds[100];
	QLNV a;
	int n;
	//cin >> n;
	//a.NhapTT(ds, n);
	ds->Load_file(ds,n);
	a.XuatTT(ds, n);


}