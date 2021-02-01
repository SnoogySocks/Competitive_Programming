#pragma once
#include <iostream>
#include <chrono>

class Benchmarker {
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> m_start_timepoint;
public:
	Benchmarker() 
	  : m_start_timepoint { std::chrono::high_resolution_clock::now() } {
	}
	~Benchmarker() {
		stop();
	}

	void stop() {

		auto end_timepoint = std::chrono::high_resolution_clock::now();

		auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_start_timepoint).time_since_epoch().count();
		auto end = std::chrono::time_point_cast<std::chrono::microseconds>(end_timepoint).time_since_epoch().count();
	
		auto duration = end - start;

		double ms = duration * 0.001;

		std::cout << duration << "us (" << ms << "ms)\n";

	}
};

