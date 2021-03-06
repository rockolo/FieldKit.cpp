/*                                                                           
 *      _____  __  _____  __     ____                                   
 *     / ___/ / / /____/ / /    /    \   FieldKit
 *    / ___/ /_/ /____/ / /__  /  /  /   (c) 2010, FIELD. All rights reserved.              
 *   /_/        /____/ /____/ /_____/    http://www.field.io           
 *   
 *	 Created by Marcus Wendt on 30/06/2010.
 */

#pragma once

#include "fieldkit/gl/GLKit_Prefix.h"
#include "fieldkit/gl/PointDataFormat.h"
#include "cinder/gl/GlslProg.h"
#include "cinder/gl/Vbo.h"

#define POINTCLOUD_DEFAULT_VS "\
attribute vec3 InVertex;\
attribute vec4 InColor;\
attribute float InSize;\
void main() {\
    vec4 vertex = vec4(InVertex, 1.0);\
    vec4 position = gl_ProjectionMatrix * gl_ModelViewMatrix * vertex;\
    gl_Position = position;\
    gl_PointSize = InSize;\
    gl_FrontColor = InColor;\
}"

#define POINTCLOUD_DEFAULT_FS "\
float smoothstepVar(float edge1, float edge2, float curve, float value) { \
    float width = edge2 - edge1; \
    float phase = (value - edge1) / width; \
    phase = clamp(phase,0.0,1.0);  \
    curve = (curve + 0.025) * 99.075;  \
    float outValue = pow(phase,curve);  \
    return outValue; \
} \
void main() { \
    vec2 tc = gl_TexCoord[0].st; \
    float dist = distance(tc, vec2(0.5, 0.5)); \
    float d = 1.0 - smoothstepVar(0.0, 0.5, 0.5, dist); \
    if(dist > 0.5) discard; \
    gl_FragColor = gl_Color * d; \
} \
"

namespace fieldkit { namespace gl {
    
	class PointCloud {
	public:
		PointCloud();
		~PointCloud();
		
		//! initializes this clouds buffer to a certain format
		void init(PointDataFormat const format, int capacity, GlslProg const shader);
		
		//! clears the buffer data
		void clear();

		//! inserts a float attribute for the current particle
		void inline put(float const& value) 
		{
			*ptr = value; ++ptr;
		}
		
		//! inserts a 2d vector attribute for the current particle
		void put(Vec2f const& v);
		
		//! inserts a 3d vector attribute for the current particle
		void put(Vec3f const& v);
		
		//! inserts a 4d vector attribute for the current particle
		void put(Vec4f const& v);
		
		//! inserts a color attribute for the current particle
		void put(ColorAf const& v);
		
		//! call this when all data for a single particle was inserted
		void insert();
		
		//! draws this cloud to screen
		void draw();

	protected:
		PointDataFormat format;
		int capacity;
		int bytesPerParticle;
		GLfloat* data;
		
		int size;
		GLfloat* ptr;
		
		Vbo vbo;
		GlslProg shader;
	};
} } // namespace fieldkit::gl