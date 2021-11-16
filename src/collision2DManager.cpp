#include <collision2DManager.h>

#include <limits>


namespace base {
    bool collision2DManager::areOverlapping(
            const collider2DComponent& collider1,
            const collider2DComponent& collider2
    ) {
        const size_t& collider1Size = collider1.points.size();
        const size_t& collider2Size = collider2.points.size();

        for (unsigned int pointIndex = 0u; pointIndex < collider1Size; ++pointIndex) {
            const unsigned int& nextPointIndex = (pointIndex + 1u) % collider1Size;
            const glm::vec2 axisProjection = glm::normalize(glm::vec2({
                -(collider1.points[nextPointIndex].y - collider1.points[pointIndex].y),
                collider1.points[nextPointIndex].x - collider1.points[pointIndex].x
            }));

            float minPoint1 = std::numeric_limits<float>::infinity();
            float maxPoint1 = -std::numeric_limits<float>::infinity();
            for (unsigned int projectedIndex = 0u; projectedIndex < collider1Size; ++projectedIndex) {
                const float dotProduct = glm::dot(collider1.points[projectedIndex], axisProjection);
                minPoint1 = std::min(minPoint1, dotProduct);
                maxPoint1 = std::max(maxPoint1, dotProduct);
            }

            float minPoint2 = std::numeric_limits<float>::infinity();
            float maxPoint2 = -std::numeric_limits<float>::infinity();
            for (unsigned int projectedIndex = 0u; projectedIndex < collider2Size; ++projectedIndex) {
                const float dotProduct = glm::dot(collider2.points[projectedIndex], axisProjection);
                minPoint2 = std::min(minPoint2, dotProduct);
                maxPoint2 = std::max(maxPoint2, dotProduct);
            }

            if (minPoint1 > maxPoint2 || minPoint2 > maxPoint1)
                return false;
        }

        return true;
    }
}
