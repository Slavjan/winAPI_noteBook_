#pragma once
#include "LabHelper.h"
#include <vector>
#include <iostream>
#include <fstream>

struct Note {
	Note() {}
	Note(std::string title, std::string text, std::string datetime) {
		this->title = title;
		this->body = text;
		this->datetime = datetime;
	}
	std::string title, body, datetime;
};

class Notebook {
protected:
	static std::vector<Note> book;
public:
	static void AddNote(Note note) {
		book.push_back(note);
		book.shrink_to_fit();
	}

	static void DeleteNote(int id) {
		if(id < 0) return;
		book.erase(book.begin() + id, book.begin() + id + 1);
		book.shrink_to_fit();
	}

	static void UpdateNote(int id, std::string title, std::string text) {
		book[id].title = title;
		book[id].body = text;
	}

	static Note GetNote(int id) {
		return book[id];
	}

	static std::vector<Note> GetNotes() {
		return book;
	}

	static bool ReadFromFile(std::string filename) {
		std::ifstream f(filename);
		while(f.is_open() && !f.eof()) {
			Note note;
			//f >> note.datetime;// f.get();
			//f >> note.title;// f.get();
			//f >> note.body;// f.get();
			std::getline(f, note.datetime, '\0');
			std::getline(f, note.title, '\0');
			std::getline(f, note.body, '\0');
			//f.get();
			book.push_back(note);
		}
		f.close();
		book.shrink_to_fit();
		//MessageBox(NULL, "Could not load from file!", "Error", MB_ICONWARNING);
		return true;
	}

	static bool SaveToFile(std::string filename) {
		std::ofstream f(filename);
		for(auto i = book.begin(); i != book.end(); ++i) {
			f << i->datetime; f.put('\0');
			f << i->title; f.put('\0');
			f << i->body; 
				if((i+1) != book.end()) f.put('\0');
		}
		f.close();
		//MessageBox(NULL, "Could not save to file!", "Error", MB_ICONWARNING);
		return true;
	}
};
