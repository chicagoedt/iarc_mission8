using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Algorithm1_quad2 : MonoBehaviour
{


    public float movementSpeed = 5.0f;
    public float clockWise = 1000.0f;
    public float counterClockWise = -5.0f;
    private int counter = 0;
    private int counter2 = 0;
    // Use this for initialization
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {
        // move forward
        if (transform.position.x > -16 && (counter2 + 4) % 4 == 0)
        {
            transform.position += Vector3.left * Time.deltaTime * movementSpeed;
            Debug.Log(counter2);
        }

        if (transform.position.x < -16)
        {
            counter2++;
        }
        
        // move to the side
        if ((counter2 + 4) % 4 == 1)
        {
            transform.Translate(0.0f, 0.0f, -1.0f);
            counter2++;
        }
       
        // move back
        if (transform.position.x < 22 && (counter2 + 4) % 4 == 2)
        {
            transform.position += -Vector3.left * Time.deltaTime * movementSpeed;
            Debug.Log(counter2);
        }

        if (transform.position.x >= 22 & (counter2 + 4) % 4 == 2)
        {
            counter2++;
        }
       
        // move to the side
        if ((counter2 + 4) % 4 == 3)
        {
            transform.Translate(0.0f, 0.0f, -1.0f);
            counter2++;
        }

    }

    void OnCollisionEnter(Collision collisionInfo)
    {
        if (collisionInfo.collider.tag == "obstacle")
        {
            Debug.Log("We hit an obstacle!");
            //transform.Translate(0.0f, 0.0f, 0.0f);
            transform.position += Vector3.left * Time.deltaTime * 0;
        }
    }

}
