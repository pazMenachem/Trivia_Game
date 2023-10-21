#pragma once
#include "./IResponse.h"


class ResponseFactory
{
public:
	static unique_ptr<IResponse> createResponse(const Json&);
};

