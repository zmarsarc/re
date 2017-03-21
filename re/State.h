#ifndef _STATE_H_

#include <utility>
#include <vector>

namespace zmarsarc {

	class Condition {

	public:

		enum Type {
			Epslion,
			Char
		};

		Type type;
		char value;

		Condition(Type t, char v) : type(t), value(v) {}
	};

	class State {

		using Transfer = std::pair<Condition, State>;

	private:
		std::vector<Transfer> next;

	public:

		bool isAccept;
		int id;

		State(int id, std::vector<Transfer> conditions) : isAccept(false), id(id), next(conditions){}
		State(int id) : isAccept(false), id(id) {}
		State() : State(0) {}

		void addNext(Condition, State);
		void delNext(Condition);
		void clrNext();
		
		State& transfer(Condition);
	};

}


#endif // _STATE_H_