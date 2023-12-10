#include <iostream>
#include <string>
#include <vector>

using namespace std;

#pragma once
/**
	@file		Shabanov_Class_Patient.h
	@brief		������������ ���� ����� ��������
	@copyright	����
	@author		������� �.�.
	@date		10-12-2023
	@version	1.0.0
\par ���������� ������:
	@ref Shabanov_Class_Patient
\par �������� �����:
	@ref Shabanov_Class_Patient
*/

/// ����� �������� ��������
/** �������� ������ �������� � ������ ��� ������ � ���
*/

class Patient
{
	string FirstName;	///< ��� ��������
	string Surname;		///< ������� ��������
	string SecondName;	///< �������� ��������
	string Adress;		///< ����� � ������������ �������
	int MedCard;		///< ����� ����������� �����
	string Diagnoz;		///< ������� ��������

public:
	/// ����������� �� ���������
	/**  ������� �������� ��� ������������� �����
	*/
	Patient() {}
	/// ����������� � ����������� ����� ������
	/**  ������� �������� � �������������� ��� ����
	\param FirstName ��� ������������ ��������
	\param Surname ������� ������������ ��������
	\param SecondName �������� ������������ ��������
	\param Adress ����� ������������ ��������
	\param MedCard ����� ����� ������������ ��������
	\param Diagnoz ������� ������������ ��������
	*/
	Patient(string F_name, string Sur_name, string S_name, string Adr, int MC, string Dia) {
		FirstName = F_name;
		Surname = Sur_name;
		SecondName = S_name;
		Adress = Adr;
		MedCard = MC;
		Diagnoz = Dia;
	}

	/// ����� ������ ��������
	void print() {
		cout << Surname << " " << FirstName << " " << SecondName << ": "
			<< MedCard << "-" << Diagnoz << endl;
	}

	/** \brief ����� ���� ��������� � ������������ ���������
	
	\param Pats ������ � ����������
	\param Dia ����������� �������
	*/
	template <typename T>
	void Find_Diag(T Pats, string Dia) {
		for (auto it = Pats.begin(); it != Pats.end(); it++) {
			Patient Pat = *it;
			if (Pat.Diagnoz == Dia) {
				print(Pat);
			}
		}
	}

	/** \brief ����� ���� ���������, ����� �������� ������� ��������� � ������������ ���������

	\param Pats ������ � ����������
	\param b ����� ������� ���������
	\param e ������ ������� ���������
	*/
	template <typename T>
	void Find_MedCard(T Pats, int b, int e) {
		for (auto it = Pats.begin(); it != Pats.end(); it++) {
			Patient Pat = *it;
			if (Pat.MedCard >= b && Pat.MedCard <= e) {
				print(Pat);
			}
		}
	}

	/** \brief ����� ���� ��������� ������������ �� ������������� ������

	\param Pats ������ � ����������
	\param Adr ����� ��������
	*/
	template <typename T>
	Patient Find_Adr(T Pats, string Adr) const {
		for (auto it = Pats.begin(); it != Pats.end(); it++) {
			Patient Pat = *it;
			if (Pat.Adress == Adr) {
				print(Pat);
			}
		}
	}

	/// ���������� ����������� �������
	~Patient();

};