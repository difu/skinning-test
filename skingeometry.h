// Copyright (C) 2020 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#ifndef SKINGEOMETRY_H
#define SKINGEOMETRY_H

#include <QtQuick3D/qquick3d.h>
#include <QtQuick3D/qquick3dgeometry.h>

#include <QVector3D>
#include <QtCore/QList>

class SkinGeometry : public QQuick3DGeometry
{
    //! [geometry]
    Q_OBJECT
    QML_NAMED_ELEMENT(SkinGeometry)
    Q_PROPERTY(QList<QVector3D> positions READ positions WRITE setPositions NOTIFY positionsChanged)
    Q_PROPERTY(QList<qint32> joints READ joints WRITE setJoints NOTIFY jointsChanged)
    Q_PROPERTY(QList<float> weights READ weights WRITE setWeights NOTIFY weightsChanged)
    Q_PROPERTY(QList<quint32> indexes READ indexes WRITE setIndexes NOTIFY indexesChanged)
    //! [geometry]

public:
    SkinGeometry(QQuick3DObject *parent = nullptr);

    QList<QVector3D> positions() const;
    QList<qint32> joints() const;
    QList<float> weights() const;
    QList<quint32> indexes() const;

    /**
     * @brief Adds a cube to the skin geometry.
     *
     * This method adds a cube to the skin geometry with the specified position and dimensions.
     * The cube is associated with the specified joints and weights.
     *
     * @param position The position of the cube.
     * @param dimensions The dimensions of the cube.
     * @param joints The list of joints associated with the cube.
     * @param weights The list of weights associated with each joint.
     */
    void addCube(QVector3D position,
                 QVector3D dimensions,
                 QList<qint32> joints,
                 QList<float> weights);

    /**
     * @brief Add a cube to the skin geometry.
     *
     * This method adds a cube to the skin geometry with the specified position and dimensions.
     * The cube is associated with the specified joint.
     *
     * @param position The position of the cube.
     * @param dimensions The dimensions of the cube.
     * @param joint The joint associated with the cube.
     */
    void addCube(QVector3D position, QVector3D dimensions, quint32 joint);

public Q_SLOTS:
    void setPositions(const QList<QVector3D> &positions);
    void setJoints(const QList<qint32> &joints);
    void setWeights(const QList<float> &weights);
    void setIndexes(const QList<quint32> &indexes);

Q_SIGNALS:
    void positionsChanged();
    void jointsChanged();
    void weightsChanged();
    void indexesChanged();

protected:
    QSSGRenderGraphObject *updateSpatialNode(QSSGRenderGraphObject *node) override;

private:
    QList<QVector3D> m_positions;
    QList<qint32> m_joints;
    QList<float> m_weights;
    QList<quint32> m_indexes;

    bool m_vertexDirty = false;
    bool m_indexDirty = false;

    QByteArray m_vertexBuffer;
    QByteArray m_indexBuffer;
};

#endif // SKINGEOMETRY_H