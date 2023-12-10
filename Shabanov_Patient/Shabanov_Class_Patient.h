#include <iostream>
#include <string>
#include <vector>

using namespace std;

#pragma once
/**
	@file		Shabanov_Class_Patient.h
	@brief		Заголовочный файл класс Пациента
	@copyright	ВоГУ
	@author		Шабанов М.С.
	@date		10-12-2023
	@version	1.0.0
\par Использует классы:
	@ref Shabanov_Class_Patient
\par Содержит класс:
	@ref Shabanov_Class_Patient
*/

/// Класс описания пациента
/** Содержит данные пациента и методы для работы с ним
*/

class Patient
{
	string FirstName;	///< Имя пациента
	string Surname;		///< Фамилия пациента
	string SecondName;	///< Отчество пациента
	string Adress;		///< Адрес в произвольном порядке
	int MedCard;		///< Номер медицинской карты
	string Diagnoz;		///< Диагноз пациента

public:
	/// Конструктор по умолчанию
	/**  Создает пациента без инициализации полей
	*/
	Patient() {}
	/// Конструктор с заполнением полей класса
	/**  Создает пациента и инициализирует его поля
	\param FirstName Имя создаваемого пациента
	\param Surname Фамилия создаваемого пациента
	\param SecondName Отчество создаваемого пациента
	\param Adress Адрес создаваемого пациента
	\param MedCard Номер карты создаваемого пациента
	\param Diagnoz Диагноз создаваемого пациента
	*/
	Patient(string F_name, string Sur_name, string S_name, string Adr, int MC, string Dia) {
		FirstName = F_name;
		Surname = Sur_name;
		SecondName = S_name;
		Adress = Adr;
		MedCard = MC;
		Diagnoz = Dia;
	}

	/// Вывод данных пациента
	void print() {
		cout << Surname << " " << FirstName << " " << SecondName << ": "
			<< MedCard << "-" << Diagnoz << endl;
	}

	/** \brief Вывод всех пациентов с определенным диагнозом
	
	\param Pats Массив с пациентами
	\param Dia Необходимый диагноз
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

	/** \brief Вывод всех пациентов, номер МедКарты которых находятся в определенном диапозоне

	\param Pats Массив с пациентами
	\param b Левая граница диапозона
	\param e Правая граница диапозона
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

	/** \brief Вывод всех пациентов проживающего по определенному адресу

	\param Pats Массив с пациентами
	\param Adr Адрес пациента
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

	/// Деструктор освобождает ресурсы
	~Patient();

};