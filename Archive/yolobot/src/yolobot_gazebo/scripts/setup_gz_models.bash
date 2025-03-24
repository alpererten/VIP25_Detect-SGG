#!/bin/bash

# Create model directories
mkdir -p /usr/share/gz/models/suv/meshes
mkdir -p /usr/share/gz/models/bus/meshes
mkdir -p /usr/share/gz/models/postbox/meshes

# Create material directories
mkdir -p /usr/share/gz/models/suv/materials/textures
mkdir -p /usr/share/gz/models/bus/materials/textures
mkdir -p /usr/share/gz/models/postbox/materials/textures

# Copy mesh files
cp -r models/suv/meshes/* /usr/share/gz/models/suv/meshes/
cp -r models/bus/meshes/* /usr/share/gz/models/bus/meshes/
cp -r models/postbox/meshes/* /usr/share/gz/models/postbox/meshes/

# Copy texture files
cp -r textures/suv/* /usr/share/gz/models/suv/materials/textures/
cp -r textures/bus/* /usr/share/gz/models/bus/materials/textures/
cp -r textures/postbox/* /usr/share/gz/models/postbox/materials/textures/

# Create symbolic links for postbox textures
mkdir -p /usr/share/gz/models/postbox/materials/textures
ln -sf /usr/share/gz/models/postbox/materials/textures/postbox_diffuse.jpg /usr/share/gz/models/postbox/meshes/postbox_diffuse.jpg
ln -sf /usr/share/gz/models/postbox/materials/textures/postbox_spec.jpg /usr/share/gz/models/postbox/meshes/postbox_spec.jpg

# Fix texture paths
sed -i 's|map_Ka suv.png|map_Ka model://suv/materials/textures/suv.png|g' /usr/share/gz/models/suv/meshes/suv.mtl
sed -i 's|map_Kd suv.png|map_Kd model://suv/materials/textures/suv.png|g' /usr/share/gz/models/suv/meshes/suv.mtl
sed -i 's|map_Ka wheels_01.png|map_Ka model://suv/materials/textures/wheels_01.png|g' /usr/share/gz/models/suv/meshes/suv.mtl
sed -i 's|map_Kd wheels_01.png|map_Kd model://suv/materials/textures/wheels_01.png|g' /usr/share/gz/models/suv/meshes/suv.mtl

sed -i 's|map_Ka bus.png|map_Ka model://bus/materials/textures/bus.png|g' /usr/share/gz/models/bus/meshes/bus.mtl
sed -i 's|map_Kd bus.png|map_Kd model://bus/materials/textures/bus.png|g' /usr/share/gz/models/bus/meshes/bus.mtl 