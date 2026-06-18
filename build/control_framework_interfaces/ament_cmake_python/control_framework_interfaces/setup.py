from setuptools import find_packages
from setuptools import setup

setup(
    name='control_framework_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('control_framework_interfaces', 'control_framework_interfaces.*')),
)
