#include <polygonData.h>

#include <cmath>


namespace utils {
    polygonData::polygonData(
            const GLfloat& originX, const GLfloat& originY, const float& radius,
            const unsigned int& pointCount, unsigned int& totalDifferentIndices,
            const GLfloat& colourRed, const GLfloat& colourGreen, const GLfloat& colourBlue
    ) {
        const float deltaTheta = 6.28318530718f / (float) pointCount;
        float theta = 0.0f;

        vertices.insert(vertices.end(), {
            originX, originY, 0.0f, 1.0f, colourRed, colourGreen, colourBlue, 0.0f, 0.0f
        });

        for (unsigned int index = 0u; index < pointCount; ++index) {
            points.insert(points.end(), {
                originX + radius * std::cos(theta), originY + radius * std::sin(theta)
            });

            vertices.insert(vertices.end(), {
                points[points.size() - 1u].x, points[points.size() - 1u].y, 0.0f, 1.0f,
                colourRed, colourGreen, colourBlue,
                0.0f, 0.0f
            });

            const unsigned int currentIndex = index + 1u;
            indices.insert(indices.end(), {
                totalDifferentIndices,
                totalDifferentIndices + currentIndex,
                totalDifferentIndices + (currentIndex) % pointCount + 1u
            });

            theta += deltaTheta;
        }

        totalDifferentIndices += pointCount + 1u;
    }
}
