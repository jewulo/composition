#pragma once

#include <string>
#include <chrono>

namespace x {
	struct session {
		std::string presenter;
		std::string title;
		std::chrono::utc_time<std::chrono::seconds> start_time;
		std::chrono::minutes duration;
	};

	std::vector<session> sessions;

	template <class F>
	auto order_by(F f);

	void run()
	{
		max_element(sessions, order_by(&session::presenter));
	}
}
