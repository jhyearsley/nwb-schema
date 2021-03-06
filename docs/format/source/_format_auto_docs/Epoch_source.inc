.. _sec-Epoch-src:

Epoch
^^^^^

**Description:** see :numref:`sec-Epoch`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    attributes:
    - dims:
      - num_links
      doc: "A sorted list mapping TimeSeries entries in the epoch to the path of the TimeSeries\
        \ within the file. Each entry in the list has the following format: \"'<i>&lt;TimeSeries_X&gt;</i>'\
        \ <b>is</b> '<i>path_to_TimeSeries</i>'\", where <i>&lt;TimeSeries_X&gt;</i> is\
        \ the name assigned to group  &lt;TimeSeries_X&gt; (below). Note that the name\
        \ and path are both enclosed in single quotes and the word \"is\" (with a single\
        \ space before and after) separate them. <b>Example list element:</b> \"'auditory_cue'\
        \ is '/stimulus/presentation/auditory_cue'\"."
      dtype: text
      name: links
      shape:
      - null
    datasets:
    - doc: Description of this epoch (&lt;epoch_X&gt;).
      dtype: text
      name: description
      quantity: '?'
    - doc: Start time of epoch, in seconds
      dtype: float64!
      name: start_time
    - doc: Stop time of epoch, in seconds
      dtype: float64!
      name: stop_time
    - dims:
      - num_tags
      doc: 'User-defined tags used throughout the epochs. Tags are to help identify or
        categorize epochs. COMMENT: E.g., can describe stimulus (if template) or behavioral
        characteristic (e.g., "lick left")'
      dtype: text
      name: tags
      quantity: '?'
      shape:
      - null
    doc: 'One of possibly many different experimental epochCOMMENT: Name is arbitrary
      but must be unique within the experiment.'
    groups:
    - datasets:
      - doc: "Epoch's start index in TimeSeries data[] field. COMMENT: This can be used\
          \ to calculate location in TimeSeries timestamp[] field"
        dtype: int32
        name: idx_start
      - doc: Number of data samples available in this time series, during this epoch.
        dtype: int32
        name: count
      doc: 'One of possibly many input or output streams recorded during epoch. COMMENT:
        Name is arbitrary and does not have to match the TimeSeries that it refers to.'
      links:
      - doc: Link to TimeSeries.  An HDF5 soft-link should be used.
        name: timeseries
        target_type: TimeSeries
      neurodata_type_def: EpochTimeSeries
      quantity: '*'
    neurodata_type_def: Epoch
    quantity: '*'


