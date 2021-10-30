//
// Created by wardh on 10/30/2021.
//

#ifndef INC_16_2_COMPOSITION_CREATURE_H
#define INC_16_2_COMPOSITION_CREATURE_H

class Creature
{
private:
    std::string m_name;
    Point2D m_location;

public:
    Creature(const std::string& name, const Point2D& location)
        : m_name{ name }, m_location{ location }
    {
    }

    friend std::ostream& operator<<(std::ostream &out, const Creature &creature)
    {
        out << creature.m_name << " is at " << creature.m_location;
        return out;
    }

    void moveTo(int x, int y)
    {
        m_location.setPoint(x, y);
    }
};
#endif //INC_16_2_COMPOSITION_CREATURE_H
