.. _sec-hdf5:

====
HDF5
====

The NWB-N format currently uses the `Hierarchical Data Format (HDF5) <https://www.hdfgroup.org/HDF5/>`_
as primary mechanism for data storage. HDF5 was selected for the NWB format because it met several of the project's
requirements. First, it is a mature data format standard with libraries
available in multiple programming languages. Second, the format's
hierarchical structure allows data to be grouped into logical
self-documenting sections. Its structure is analogous to a file system
in which its "groups" and "datasets" correspond to directories and
files. Groups and datasets can have attributes that provide additional
details, such as authorities' identifiers. Third, its linking feature
enables data stored in one location to be transparently accessed from
multiple locations in the hierarchy. The linked data can be external to
the file. Fourth, HDF5 is widley supported across programming languages
(e.g., C, C++, Python, MATLAB, R among others) and tools, such as,
`HDFView <https://www.hdfgroup.org/products/java/hdfview/>`__, a free,
cross-platform application, can be used to open a file and browse data.
Finally, ensuring the ongoing accessibility of HDF-stored data is the
mission of The HDF Group, the nonprofit that is the steward of the
technology.

Format Mapping
==============

Here we describe the mapping of NWB primitives (e.g,. Groups, Datasets, Attributes, Links etc.) used by
the NWB format and specification to HDF5 storage primitives. As the NWB-N format was designed with HDF5
in mind, the high-level mapping between the format specification and HDF5 is quite simple:

.. tabularcolumns:: |p{4cm}|p{11cm}|

.. table:: Mapping of groups
    :class: longtable

    =============  ===============================================
    NWB Primitive  HDF5 Primitive
    =============  ===============================================
    Group          Group
    Dataset        Dataset
    Attribute      Attribute
    Link           Soft Link
    =============  ===============================================


Key Mapping
===========

Here we describe the mapping of keys from the specifcation language to HDF5 storage objects:

Groups
------

.. tabularcolumns:: |p{4cm}|p{11cm}|

.. table:: Mapping of groups
    :class: longtable

    ============================  ======================================================================================
    NWB Key                       HDF5
    ============================  ======================================================================================
    name                          Name of the Group in HDF5
    doc                           HDF5 attribute doc on the HDF5 group
    groups                        HDF5 groups within the HDF5 group
    datasets                      HDF5 datasets within the HDF5 group
    attributes                    HDF5 attributes on the HDF5 group
    links                         HDF5 SoftLinks within the HDF5 group
    linkable                      Not mapped; Stored in schema only
    quantity                      Not mapped; Number of appearances of the dataset.
    neurodata_type                Attribute ``neurodata_type``
    namespace ID                  Attribute ``neurodata_namespace``
    ============================  ======================================================================================


Datasets
--------

.. tabularcolumns:: |p{4cm}|p{11cm}|

.. table:: Mapping of datasets
    :class: longtable


    ============================  ======================================================================================
    NWB Key                       HDF5
    ============================  ======================================================================================
    name                          Name of the dataset in HDF5
    doc                           HDF5 attribute doc on the HDF5 dataset
    dtype                         Data type of the HDF5 dataset
    shape                         Shape of the HDF5 dataset if the shape is fixed, otherwise shape defines the maxshape
    dims                          Not mapped
    attributes                    HDF5 attributes on the HDF5 group
    linkable                      Not mapped; Stored in schema only
    quantity                      Not mapped; Number of appearances of the dataset.
    neurodata_type                Attribute ``neurodata_type``
    namespace ID                  Attribute ``neurodata_namespace``
    ============================  ======================================================================================

.. note::

    * TODO Update mapping of namespace ID
    * TODO Update mapping of dims

Attriutes
---------

.. tabularcolumns:: |p{4cm}|p{11cm}|

.. table:: Mapping of attributes
    :class: longtable

    ============================  ======================================================================================
    NWB Key                       HDF5
    ============================  ======================================================================================
    name                          Name of the attribute in HDF5
    doc                           Not mapped; Stored in schema only
    dtype                         Data type of the HDF5 attribute
    shape                         Shape of the HDF5 dataset if the shape is fixes, otherwise shape defines the maxshape
    dims                          Not mapped; Reflected by the shape of the attribute data
    required                      Not mapped; Stored in schema only
    parent                        Not mapped; In HDF5 all attributes are explicitly tied to the parent.
    value                         Data value of the attribute
    ============================  ======================================================================================


Links
-----

.. tabularcolumns:: |p{4cm}|p{11cm}|

.. table:: Mapping of links
    :class: longtable

    ============================  ======================================================================================
    NWB Key                       HDF5
    ============================  ======================================================================================
    name                          Name of the HDF5 Soft Link
    doc                           Not mapped; Stored in schema only
    target_type                   Not mapped. The target type is determined by the type of the target of the HDF5 link
    ============================  ======================================================================================
