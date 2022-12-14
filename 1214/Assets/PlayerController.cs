using UnityEngine;
using UnityEngine.SceneManagement;

public class PlayerController : MonoBehaviour
{
    [SerializeField]
    private float minHeight;
    private Movement3D movement3D;

    private void Awake()
    {
        movement3D = GetComponent<Movement3D>();
    }

    private void Update()
    {
        float x = Input.GetAxis("Horizontal");
        float z = Input.GetAxis("Vertical");

        if(x!=0 || z != 0)
        {
            movement3D.MoveTo(new Vector3(x, 0, z));
        }
        ChangeSceneFallDown();
    }

    private void ChangeSceneFallDown()
    {
        if(transform.position.y < minHeight)
        {
            SceneManager.LoadScene(SceneManager.GetActiveScene().name);
        }
    }
}
