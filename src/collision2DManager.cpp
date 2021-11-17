#include <collision2DManager.h>

#include <limits>


namespace base {
    glm::vec2 collision2DManager::getOverlap(
            const collider2DComponent& from,
            const collider2DComponent& to
    ) {
        const size_t& fromSize = from.points.size();
        const size_t& toSize = to.points.size();

        float overlapDistance = std::numeric_limits<float>::infinity();
        glm::vec2 overlapDirection;

        for (unsigned int pointIndex = 0u; pointIndex < fromSize; ++pointIndex) {
            const unsigned int& nextPointIndex = (pointIndex + 1u) % fromSize;
            const glm::vec2 axisProjection = glm::normalize(glm::vec2({
                from.points[nextPointIndex].y - from.points[pointIndex].y,
                from.points[pointIndex].x - from.points[nextPointIndex].x
            }));

            float minPointFrom = std::numeric_limits<float>::infinity();
            float maxPointFrom = -std::numeric_limits<float>::infinity();
            for (unsigned int projectedIndex = 0u; projectedIndex < fromSize; ++projectedIndex) {
                const float dotProduct = glm::dot(axisProjection, from.points[projectedIndex]);
                minPointFrom = std::min(minPointFrom, dotProduct);
                maxPointFrom = std::max(maxPointFrom, dotProduct);
            }

            float minPointTo = std::numeric_limits<float>::infinity();
            float maxPointTo = -std::numeric_limits<float>::infinity();
            for (unsigned int projectedIndex = 0u; projectedIndex < toSize; ++projectedIndex) {
                const float dotProduct = glm::dot(axisProjection, to.points[projectedIndex]);
                minPointTo = std::min(minPointTo, dotProduct);
                maxPointTo = std::max(maxPointTo, dotProduct);
            }

            if (maxPointFrom < minPointTo || minPointFrom > maxPointTo)
                return { 0.0f, 0.0f };

            const float currentOverlapDistance = std::min(
                    std::abs(maxPointFrom - minPointTo),
                    std::abs(minPointFrom - maxPointTo)
            ) + (float) (
                    (minPointTo <= minPointFrom && maxPointFrom <= maxPointTo)
                    || (minPointFrom <= minPointTo && maxPointTo <= maxPointFrom)
            ) * std::min(std::abs(minPointFrom - minPointTo), std::abs(maxPointFrom - maxPointTo)) / 2.0f;

            if (currentOverlapDistance < overlapDistance) {
                overlapDistance = currentOverlapDistance;
                overlapDirection = (float) (2 * (maxPointFrom >= maxPointTo) - 1) * axisProjection;
            }
        }

        return overlapDistance * overlapDirection;
    }
}
