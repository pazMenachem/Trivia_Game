#pragma once
#include "IRequest.h"


/**
 * @brief Factory for creating IRequest objects.
 *
 * This class serves as a factory for creating IRequest objects based on a provided
 * unsigned char identifier. It allows the creation of specific request objects
 * to handle different types of requests.
 */
class RequestFactory {
public:
    /**
     * @brief Create an IRequest object based on an identifier.
     *
     * This method creates an IRequest object based on the provided unsigned char
     * identifier (Check Utils.h for request codes), which is used to determine the type of request to be created.
     *
     * @param identifier The unsigned char identifier representing the request type.
     * @return A pointer to the created IRequest object.
     */
    IRequest* createRequest(const unsigned char identifier) const;
};
