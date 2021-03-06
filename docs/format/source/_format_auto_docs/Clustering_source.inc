.. _sec-Clustering-src:

Clustering
^^^^^^^^^^

**Extends:** :ref:`Interface <sec-Interface>`

**Description:** see :numref:`sec-Clustering`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    attributes:
    - doc: Value is 'Clustered spike data, whether from automatic clustering tools (eg,
        klustakwik) or as a result of manual sorting'
      dtype: text
      name: help
      value: Clustered spike data, whether from automatic clustering tools (eg, klustakwik)
        or as a result of manual sorting
    datasets:
    - dims:
      - num_events
      doc: Cluster number of each event
      dtype: int32
      name: num
      shape:
      - null
    - dims:
      - num_clusters
      doc: List of cluster number that are a part of this set (cluster numbers can be
        non- continuous)
      dtype: int32
      name: cluster_nums
      shape:
      - null
    - dims:
      - num_events
      doc: Times of clustered events, in seconds. This may be a link to times field in
        associated FeatureExtraction module.
      dtype: float64!
      name: times
      shape:
      - null
    - dims:
      - num_clusters
      doc: Maximum ratio of waveform peak to RMS on any channel in the cluster (provides
        a basic clustering metric).
      dtype: float32
      name: peak_over_rms
      shape:
      - null
    - doc: Description of clusters or clustering, (e.g. cluster 0 is noise, clusters curated
        using Klusters, etc)
      dtype: text
      name: description
    doc: Clustered spike data, whether from automatic clustering tools (e.g., klustakwik)
      or as a result of manual sorting.
    name: Clustering
    neurodata_type_def: Clustering
    neurodata_type_inc: Interface


