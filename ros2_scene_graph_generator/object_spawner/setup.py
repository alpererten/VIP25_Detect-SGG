from setuptools import setup
import os
from glob import glob

package_name = 'object_spawner'

setup(
    name=package_name,
    version='0.0.0',
    packages=['object_spawner'],
    data_files=[
        # Install launch files
        (f'share/{package_name}/launch', glob('launch/*.launch.py')),
        # Install package.xml
        (f'share/{package_name}', ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='user',
    maintainer_email='user@todo.todo',
    description='Spawns apples, banana, and tennis ball in Gazebo.',
    license='MIT',
    tests_require=['pytest'],
    entry_points={},
)
