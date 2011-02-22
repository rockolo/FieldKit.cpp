/*                                                                           
 *      _____  __  _____  __     ____                                   
 *     / ___/ / / /____/ / /    /    \   FieldKit
 *    / ___/ /_/ /____/ / /__  /  /  /   (c) 2010, FIELD. All rights reserved.              
 *   /_/        /____/ /____/ /_____/    http://www.field.io           
 *   
 *	 Created by Marcus Wendt on 20/05/2010.
 */

#pragma once

//! FieldKit globals
namespace fieldkit {};

// Create a namepace alias as shorthand for fieldkit::
namespace fk = fieldkit;

#include "fieldkit/Logger.h"

// DEPENDENCIES
// stl
#include <list>
#include <vector>
#include <string>
using namespace std;

// boost
#include <boost/foreach.hpp>