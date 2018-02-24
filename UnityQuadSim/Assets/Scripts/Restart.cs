using UnityEngine;
using UnityEngine.SceneManagement;
using System.Collections;

public class Restart : MonoBehaviour {

    void Update() {
        if(Input.GetKeyDown(KeyCode.R)) {
            SceneManager.LoadScene( SceneManager.GetActiveScene().name );
        }    
    }

}
