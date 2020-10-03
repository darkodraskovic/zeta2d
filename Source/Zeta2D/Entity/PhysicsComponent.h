#ifndef PHYSICS_COMPONENT_H
#define PHYSICS_COMPONENT_H

#include "Component.h"
#include "TransformComponent.h"

using namespace glm;

namespace Zeta2D {

    class PhysicsComponent : public Component {
    public:
        virtual void Update(float deltaTime) {
            auto tc = owner->GetComponent<TransformComponent>();

            // linear
            ApplyForce(gravity_);
            Drag();
            velocity_ += acceleration_ * deltaTime;

            if (length(velocity_) < minSpeed_) {
                velocity_ *= 0.f;
            } else {
                velocity_ = clamp(velocity_, -maxVelocity_, maxVelocity_);
            }
            
            tc->position_ += velocity_ * deltaTime;
            acceleration_ *= 0.f;

            // angular
            aAcceleration_ += (-aDrag_ * aVelocity_ * aVelocity_) / mass_;
            aVelocity_ += aAcceleration_ * deltaTime;
            
            if (aVelocity_ < minASpeed_) {
                aVelocity_ *= 0.0f;
            } else {
                aVelocity_ = clamp(aVelocity_, -maxAVelocity_, maxAVelocity_);
            }

            tc->rotation_ += aVelocity_ * deltaTime;
            aAcceleration_ *= 0.f;
        };

        float mass_ = 1.0;
        
        // linear
        vec2 velocity_{0,0};
        float minSpeed_ = 1.f;
        vec2 maxVelocity_{500,500};
        vec2 acceleration_{0,0};
        float drag_ = 0;
        vec2 gravity_{0,0};

        // angular
        float aVelocity_ = 0;
        float minASpeed_ = 1.f;
        float maxAVelocity_ = 720.0f;
        float aAcceleration_ = 0;
        float aDrag_ = 0;

    private:
         void ApplyForce(const vec2& force) {
            acceleration_ += force / mass_;
        }
        
        void Drag() {
            float speed = length(velocity_);
            if (!speed) return;
            vec2 drag = drag_ * speed * speed * normalize(-velocity_);
            ApplyForce(drag);
        }
    };

}  // Zeta2D

#endif /* PHYSICS_COMPONENT_H */
