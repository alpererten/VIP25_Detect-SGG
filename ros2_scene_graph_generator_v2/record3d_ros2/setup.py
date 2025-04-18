from setuptools import setup

package_name = 'record3d_ros2'

setup(
    name=package_name,
    version='0.0.1',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Your Name',
    maintainer_email='your@email.com',
    description='ROS2 wrapper for Record3D iPhone RGB-D stream',
    license='MIT',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'record3d_publisher = record3d_ros2.record3d_publisher:main'
        ],
    },
)

