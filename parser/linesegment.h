// This file is a part of "Candle" application.
// This file was originally ported from "LineSegment.java" class
// of "Universal GcodeSender" application written by Will Winder
// (https://github.com/winder/Universal-G-Code-Sender)

// Copyright 2015-2016 Hayrullin Denis Ravilevich

#ifndef LINESEGMENT_H
#define LINESEGMENT_H

#include <QVector3D>
#include "pointsegment.h"

class LineSegment
{
public:
    LineSegment();
    LineSegment(QVector3D a, QVector3D b, int num);
    explicit LineSegment(LineSegment *initial);
    ~LineSegment();

    int getLineNumber();
    QList<QVector3D> getPointArray();
    QList<double> getPoints();

    QVector3D &getStart();
    void setStart(QVector3D vector);

    QVector3D &getEnd();
    void setEnd(QVector3D vector);

    void setToolHead(int head);
    int getToolhead();
    void setSpeed(double s);
    double getSpeed();
    void setIsZMovement(bool isZ);
    bool isZMovement();
    void setIsArc(bool isA);
    bool isArc();
    void setIsFastTraverse(bool isF);
    bool isFastTraverse();

    bool contains(const QVector3D &point);

    [[nodiscard]] bool drawn() const;
    void setDrawn(bool drawn);

    [[nodiscard]] bool isMetric() const;
    void setIsMetric(bool isMetric);

    [[nodiscard]] bool isAbsolute() const;
    void setIsAbsolute(bool isAbsolute);

    [[nodiscard]] bool isHighlighted() const;
    void setIsHighlighted(bool isHighlighted);

    [[nodiscard]] int vertexIndex() const;
    void setVertexIndex(int vertexIndex);

    [[nodiscard]] double getSpindleSpeed() const;
    void setSpindleSpeed(double spindleSpeed);

    [[nodiscard]] double getDwell() const;
    void setDwell(double dwell);

    [[nodiscard]] bool isClockwise() const;
    void setIsClockwise(bool isClockwise);

    [[nodiscard]] PointSegment::planes plane() const;
    void setPlane(const PointSegment::planes &plane);

private:
    int m_toolhead;
    double m_speed;
    double m_spindleSpeed;
    double m_dwell;
    QVector3D m_first, m_second;

    // Line properties
    bool m_isZMovement;
    bool m_isArc;
    bool m_isClockwise;
    bool m_isFastTraverse;
    int m_lineNumber;
    bool m_drawn;
    bool m_isMetric;
    bool m_isAbsolute;
    bool m_isHightlight;
    int m_vertexIndex;

    PointSegment::planes m_plane;
};

#endif // LINESEGMENT_H
