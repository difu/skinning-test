# skinning-test
Silly testbed to learn skinning

The code is based on the [Skinning Example by Qt](https://doc.qt.io/qt-6/qtquick3d-skinning-example.html).

Take a look at the [Video](https://www.youtube.com/watch?v=yhcQG4zJkOw).

This example has three hierarchical joints:
```qmllang
   Node {
        id: joint0
         Node {
            id: joint1
            position.y:10
            Node {
                id: joint2
                position.y:10
            }
        }
    }
```

Each joint has its own inverse bind matrix. From the joint offsets you can easily derive the inverse bind matrices.
```qmllang
Skin {
    id: skin0
    joints: [
        joint0,
        joint1,
        joint2,
    ]
    //! [poses]
    inverseBindPoses: [
        Qt.matrix4x4(1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1),
        Qt.matrix4x4(1, 0, 0, 0,
            0, 1, 0, -10,
            0, 0, 1, 0,
            0, 0, 0, 1),
        Qt.matrix4x4(1, 0, 0, 0,
            0, 1, 0, -20,
            0, 0, 1, 0,
            0, 0, 0, 1)
    ]
    //! [poses]
}
```

The corresponding mesh consists of three cubes. Each cube is attached to 1 joint.
```c++
    addCube(QVector3D(0, 0, 0), QVector3D(10, 10, 10), 0);
    addCube(QVector3D(0, 10.1, 0), QVector3D(10, 10, 10), 1);
    addCube(QVector3D(0, 20.2, 0), QVector3D(10, 10, 10), 2);
```
