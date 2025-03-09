#!/bin/bash

# Fix SUV MTL file
sed -i 's|map_Ka suv.png|map_Ka model://suv/materials/textures/suv.png|g' /usr/share/gz/models/suv/meshes/suv.mtl
sed -i 's|map_Kd suv.png|map_Kd model://suv/materials/textures/suv.png|g' /usr/share/gz/models/suv/meshes/suv.mtl
sed -i 's|map_Ka wheels_01.png|map_Ka model://suv/materials/textures/wheels_01.png|g' /usr/share/gz/models/suv/meshes/suv.mtl
sed -i 's|map_Kd wheels_01.png|map_Kd model://suv/materials/textures/wheels_01.png|g' /usr/share/gz/models/suv/meshes/suv.mtl

# Fix Bus MTL file
sed -i 's|map_Ka bus.png|map_Ka model://bus/materials/textures/bus.png|g' /usr/share/gz/models/bus/meshes/bus.mtl
sed -i 's|map_Kd bus.png|map_Kd model://bus/materials/textures/bus.png|g' /usr/share/gz/models/bus/meshes/bus.mtl 