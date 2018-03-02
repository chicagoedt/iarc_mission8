using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class randomMovement : MonoBehaviour {
    /*
     IGNORE THIS SCRIPT
     */
    void Start()
    {
        InvokeRepeating("SetRandomPos", 0, 1);
    }

    void SetRandomPos()
    {
        Vector3 temp = new Vector3(Random.Range(-19.0f, 19.0f), Random.Range(-2.0f, -2.0f), Random.Range(-8.5f, 8.5f));
        transform.position = temp;
    }

    private void FixedUpdate()
    {
        SetRandomPos();
    }
}
