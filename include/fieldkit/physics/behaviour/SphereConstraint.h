/*                                                                           
 *      _____  __  _____  __     ____                                   
 *     / ___/ / / /____/ / /    /    \   FieldKit
 *    / ___/ /_/ /____/ / /__  /  /  /   (c) 2010, FIELD. All rights reserved.              
 *   /_/        /____/ /____/ /_____/    http://www.field.io           
 *   
 *	 Created by Marcus Wendt on 06/06/2010.
 */

#pragma once

#include "fieldkit/physics/PhysicsKit.h"
#include "fieldkit/math/Sphere.h"

namespace fieldkit { namespace physics {
	
	//! Constrains the particle to the inside or outside of a sphere
	class SphereConstraint : public Constraint, public fk::math::Sphere {
	public:
		bool isBoundingSphere;
		
		SphereConstraint(Sphere sphere_ = Sphere(), bool isBoundingSphere_ = false) :
			isBoundingSphere(isBoundingSphere_) {
			set(sphere_);
		};
		
		void apply(Particle* p);
	};
	
} } // namespace fieldkit::physics