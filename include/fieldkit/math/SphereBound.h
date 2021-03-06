/*                                                                           
 *      _____  __  _____  __     ____                                   
 *     / ___/ / / /____/ / /    /    \   FieldKit
 *    / ___/ /_/ /____/ / /__  /  /  /   (c) 2010, FIELD. All rights reserved.              
 *   /_/        /____/ /____/ /_____/    http://www.field.io           
 *   
 *	 Created by Marcus Wendt on 06/06/2010.
 */

#pragma once

#include "fieldkit/math/BoundingVolume.h"

namespace fieldkit {

	//! A Sphere that can be used as bounding volume
	class SphereBound : public BoundingVolume {
	public:
		float radius;
		
		//! Constructs a new sphere with the given radius
		SphereBound(float radius_);

		//! Constructs a new sphere at the given position with the given radius
		SphereBound(Vec3f center = Vec3f::zero(), float radius = 1.0f);

		void set(SphereBound sphere);
		
		// Bounding Volume
		bool contains(Vec3f const& p);
		
		// Accessors		
		void setRadius(float value) { radius = value; };
		float getRadius() { return radius; };
		
	protected:
	};
	
} // namespace fieldkit