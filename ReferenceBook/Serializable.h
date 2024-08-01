#pragma once

#include<iostream>

class Serializable {
public:
	virtual void downloadInfo(const std::string& path) = 0;
	
	virtual void uploadInfo(const std::string& path) const = 0;

	virtual ~Serializable() = default;
};