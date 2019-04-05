#include<iostream>
#include<conio.h>
using namespace std;

class pegawai{
	protected:
		string nama;
		string nip;
		string statPeg="Available";
	public:
		void setDataPegawai(string nama, string nip);
		void showDataPegawai();
		virtual void showAvailability();
};

void pegawai::setDataPegawai(string nama, string nip){
	this->nama=nama;
	this->nip=nip;		
}
void pegawai::showDataPegawai(){
	cout<<"Nama    : "<<this->nama<<endl;
	cout<<"NIP     : "<<this->nip<<endl;
}
void pegawai::showAvailability(){
	cout<<"Status  : "<<this->statPeg<<endl;
}
//===============================================================================
class kepegawaian{
	protected:
		string jabatan;
		string divisi;
	public:
		void setDataKepegawaian(string divisi,string jabatan);
		void showDataKepegawaian();
};

void kepegawaian::setDataKepegawaian(string divisi,string jabatan){
	this->divisi=divisi;
	this->jabatan=jabatan;
}

void kepegawaian::showDataKepegawaian(){
	cout<<"Divisi  : "<<this->divisi<<endl;
	cout<<"Jabatan : "<<this->jabatan<<endl;
}
//===============================================================================
class project : public pegawai,public kepegawaian{
	private:
		string projectName;
		string priority;
		string status;
	public:
		void setDataProject(string projectName,string priority);
		void showDataProject();
		void showAvailability() override;
	
};

void project::setDataProject(string projectName,string priority){
	this->projectName=projectName;
	this->priority=priority;
	this->status="Started";
}

void project::showDataProject(){
	cout<<"Project           : "<<this->projectName<<endl;
	cout<<"Priority          : "<<this->priority<<endl;
	cout<<"Status            : "<<this->status<<endl;	
	cout<<"Ditugaskan Kepada : "<<this->nama<<endl;
	
}

void project::showAvailability(){
	this->statPeg="On Duty";
	cout<<"Status Penugasan "<<this->nama<<" Telah Diubah Menjadi "<<this->statPeg<<endl;
}
//===============================================================================
int main(){
	string Tnama,Tnip,Tdiv,Tjab,Tpname,Tprio;
	
	project proj;
	
	cout<<"Masukkan Data Pegawai/Teknisi Yang Akan Di Tugaskan"<<endl;
	cout<<"Nama    : ";cin>>Tnama;
	cout<<"NIP     : ";cin>>Tnip;
	cout<<"Divisi  : ";cin>>Tdiv;
	cout<<"Jabatan : ";cin>>Tjab;
	cout<<endl;
	cout<<"Masukkan Detail Project / Tugas"<<endl;
	cout<<"Project Name : ";cin>>Tpname;
	cout<<"Priority     : ";cin>>Tprio;
	
	system("cls");
	
	proj.setDataPegawai(Tnama,Tnip);
	proj.setDataKepegawaian(Tdiv,Tjab);
	proj.setDataProject(Tpname,Tprio);
	cout<<"Data Pegawai ~"<<endl;
	proj.showDataPegawai();
	proj.showDataKepegawaian();
	cout<<endl<<endl;
	cout<<"Data Project ~"<<endl;
	proj.showDataProject();
	cout<<endl<<endl;
	cout<<"Status Penugasan ~"<<endl;
	proj.showAvailability();
	
	return 0;
}