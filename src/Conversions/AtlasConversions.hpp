#pragma once
#include "atlas/core/matrix/mat4.h"
#include "atlas/physics/shapes/shape2d.h"

inline void localToWorld(
    const atlas::physics::shape::Box2D &local,
    const atlas::core::mat4::Mat4 &worldTRS,
    atlas::physics::shape::Box2D &outWorld) {
    using namespace atlas::core;

    vec::Vec3 translation;
    quat::Quat rotation;
    vec::Vec3 scale;

    mat4::decomposeTRS(worldTRS, translation, rotation, scale);

    outWorld.center = {translation.x + local.center.x, translation.y + local.center.y};

    mat4::Mat4 rotMat = mat4::rotate(rotation);

    vec::Vec3 worldAxis0 = mat4::transformDirection(
        rotMat,
        {local.axes[0].x, local.axes[0].y, 0.f}
    );

    vec::Vec3 worldAxis1 = mat4::transformDirection(
        rotMat,
        {local.axes[1].x, local.axes[1].y, 0.f}
    );

    worldAxis0.normalize();
    worldAxis1.normalize();

    outWorld.axes[0] = {worldAxis0.x, worldAxis0.y};
    outWorld.axes[1] = {worldAxis1.x, worldAxis1.y};

    outWorld.halfExtents.x = local.halfExtents.x * scale.x;
    outWorld.halfExtents.y = local.halfExtents.y * scale.y;
}

inline void localToWorld(
    const atlas::physics::shape::Circle &local,
    const atlas::core::mat4::Mat4 &worldTRS,
    atlas::physics::shape::Circle &outWorld) {
    using namespace atlas::core;

    vec::Vec3 translation;
    quat::Quat rotation;
    vec::Vec3 scale;

    mat4::decomposeTRS(worldTRS, translation, rotation, scale);

    outWorld.center = {translation.x + local.center.x, translation.y + local.center.y};
    outWorld.radius = std::max(scale.x, scale.y);
}
