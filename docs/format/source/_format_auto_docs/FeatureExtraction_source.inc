.. _sec-FeatureExtraction-src:

FeatureExtraction
^^^^^^^^^^^^^^^^^

**Extends:** :ref:`Interface <sec-Interface>`

**Description:** see :numref:`sec-FeatureExtraction`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    attributes:
    - doc: Value is 'Container for salient features of detected events'
      dtype: text
      name: help
      value: Container for salient features of detected events
    datasets:
    - dims:
      - num_events
      doc: Times of events that features correspond to (can be a link).
      dtype: float64!
      name: times
      shape:
      - null
    - dims:
      - num_features
      doc: Description of features (eg, "PC1") for each of the extracted features.
      dtype: text
      name: description
      shape:
      - null
    - dims:
      - num_events
      - num_channels
      - num_features
      doc: Multi-dimensional array of features extracted from each event.
      dtype: float32
      name: features
      shape:
      - null
      - null
      - null
    doc: Features, such as PC1 and PC2, that are extracted from signals stored in a SpikeEvent
      TimeSeries or other source.
    links:
    - doc: link to ElectrodeGroup group that generated this TimeSeries data
      name: electrode_group
      target_type: ElectrodeGroup
    name: FeatureExtraction
    neurodata_type_def: FeatureExtraction
    neurodata_type_inc: Interface


