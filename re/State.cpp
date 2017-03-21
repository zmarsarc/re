#include "State.h"
#include <algorithm>

void zmarsarc::State::addNext(Condition c, State s) {
	next.push_back(Transfer(c, s));
}

void zmarsarc::State::delNext(Condition c) {
	std::remove_if(
		next.begin(),
		next.end(),
		[&](Transfer t){ return (t.first.type == c.type && t.first.value == c.value); }
	);
}

void zmarsarc::State::clrNext() {
	next.clear();
}

zmarsarc::State& zmarsarc::State::transfer(Condition c) {
	auto it = std::find_if(
		next.begin(),
		next.end(),
		[&](Transfer t) { return (t.first.type == c.type && t.first.value == c.value); }
	);
	return (it == next.end() ? *this : it->second);
}
